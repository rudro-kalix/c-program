#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Comp{
    int id;
    char name[30];
    char cat[30];
    char des[120];
    char st[15];
};

struct Admin{
    char user[20];
    char pass[20];
};

int nextId();
void addComp();
void checkStatus();
void showAll();
void searchComp();
void updateStatus();
void deleteComp();
void pendingList();
void solvedList();
void reportData();
int adminLogin();
void createAdmin();

int nextId(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;
    int id=1000;

    if(fp==NULL) return 1001;

    while(fread(&c,sizeof(c),1,fp))
        id=c.id;

    fclose(fp);
    return id+1;
}

void createAdmin(){
    FILE *fp=fopen("admin.dat","rb");
    struct Admin a;

    if(fp==NULL){
        fp=fopen("admin.dat","wb");
        strcpy(a.user,"admin");
        strcpy(a.pass,"1234");
        fwrite(&a,sizeof(a),1,fp);
    }

    if(fp) fclose(fp);
}

int adminLogin(){
    FILE *fp=fopen("admin.dat","rb");
    struct Admin a;
    char u[20],p[20];

    printf("\nUsername: ");
    scanf("%19s",u);

    printf("Password: ");
    scanf("%19s",p);

    while(fread(&a,sizeof(a),1,fp)){
        if(strcmp(u,a.user)==0 && strcmp(p,a.pass)==0){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void addComp(){
    FILE *fp=fopen("data.dat","ab");
    struct Comp c;

    c.id=nextId();

    printf("\nName: ");
    scanf(" %29[^\n]",c.name);

    printf("Category: ");
    scanf(" %29[^\n]",c.cat);

    printf("Description: ");
    scanf(" %119[^\n]",c.des);

    strcpy(c.st,"Pending");

    fwrite(&c,sizeof(c),1,fp);
    fclose(fp);

    printf("\nComplaint Added");
    printf("\nID: %d\n",c.id);
}

void checkStatus(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;
    int id,f=0;

    printf("Enter ID: ");
    scanf("%d",&id);

    while(fread(&c,sizeof(c),1,fp)){
        if(c.id==id){
            printf("\nName: %s",c.name);
            printf("\nStatus: %s\n",c.st);
            f=1;
            break;
        }
    }

    if(!f) printf("Not Found\n");

    fclose(fp);
}

void showAll(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;

    if(fp==NULL){
        printf("No Data\n");
        return;
    }

    while(fread(&c,sizeof(c),1,fp)){
        printf("\n-------------------\n");
        printf("ID: %d\n",c.id);
        printf("Name: %s\n",c.name);
        printf("Category: %s\n",c.cat);
        printf("Description: %s\n",c.des);
        printf("Status: %s\n",c.st);
    }

    fclose(fp);
}

void searchComp(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;
    int id,f=0;

    printf("Enter ID: ");
    scanf("%d",&id);

    while(fread(&c,sizeof(c),1,fp)){
        if(c.id==id){
            printf("\nID: %d\n",c.id);
            printf("Name: %s\n",c.name);
            printf("Category: %s\n",c.cat);
            printf("Description: %s\n",c.des);
            printf("Status: %s\n",c.st);
            f=1;
            break;
        }
    }

    if(!f) printf("Not Found\n");

    fclose(fp);
}

void updateStatus(){
    FILE *fp=fopen("data.dat","rb+");
    struct Comp c;
    int id,f=0;

    printf("Enter ID: ");
    scanf("%d",&id);

    while(fread(&c,sizeof(c),1,fp)){
        if(c.id==id){
            printf("New Status (Pending/Working/Solved): ");
            scanf(" %14[^\n]",c.st);

            fseek(fp,-(long)sizeof(c),SEEK_CUR);
            fwrite(&c,sizeof(c),1,fp);

            printf("Updated\n");
            f=1;
            break;
        }
    }

    if(!f) printf("Not Found\n");

    fclose(fp);
}

void deleteComp(){
    FILE *fp=fopen("data.dat","rb");
    FILE *tp=fopen("temp.dat","wb");
    struct Comp c;
    int id,f=0;

    printf("Enter ID: ");
    scanf("%d",&id);

    while(fread(&c,sizeof(c),1,fp)){
        if(c.id!=id)
            fwrite(&c,sizeof(c),1,tp);
        else
            f=1;
    }

    fclose(fp);
    fclose(tp);

    remove("data.dat");
    rename("temp.dat","data.dat");

    if(f) printf("Deleted\n");
    else printf("Not Found\n");
}

void pendingList(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;

    while(fread(&c,sizeof(c),1,fp)){
        if(strcmp(c.st,"Pending")==0){
            printf("\n%d  %s  %s\n",c.id,c.name,c.st);
        }
    }

    fclose(fp);
}

void solvedList(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;

    while(fread(&c,sizeof(c),1,fp)){
        if(strcmp(c.st,"Solved")==0){
            printf("\n%d  %s  %s\n",c.id,c.name,c.st);
        }
    }

    fclose(fp);
}

void reportData(){
    FILE *fp=fopen("data.dat","rb");
    struct Comp c;
    int t=0,p=0,w=0,s=0;

    while(fread(&c,sizeof(c),1,fp)){
        t++;

        if(strcmp(c.st,"Pending")==0) p++;
        else if(strcmp(c.st,"Working")==0) w++;
        else if(strcmp(c.st,"Solved")==0) s++;
    }

    fclose(fp);

    printf("\nTotal   : %d",t);
    printf("\nPending : %d",p);
    printf("\nWorking : %d",w);
    printf("\nSolved  : %d\n",s);
}

int main(){
    int ch,x;

    createAdmin();

    while(1){
        printf("\n===== Complaint Management System =====\n");
        printf("1. User\n");
        printf("2. Admin\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d",&ch);

        if(ch==1){
            do{
                printf("\n1. File Complaint\n");
                printf("2. Check Status\n");
                printf("3. Back\n");
                printf("Choice: ");
                scanf("%d",&x);

                if(x==1) addComp();
                else if(x==2) checkStatus();

            }while(x!=3);
        }

        else if(ch==2){
            if(!adminLogin()){
                printf("Wrong Login\n");
                continue;
            }

            do{
                printf("\n--- Admin Menu ---\n");
                printf("1. View All\n");
                printf("2. Search\n");
                printf("3. Update Status\n");
                printf("4. Delete\n");
                printf("5. Pending\n");
                printf("6. Solved\n");
                printf("7. Report\n");
                printf("8. Back\n");
                printf("Choice: ");
                scanf("%d",&x);

                if(x==1) showAll();
                else if(x==2) searchComp();
                else if(x==3) updateStatus();
                else if(x==4) deleteComp();
                else if(x==5) pendingList();
                else if(x==6) solvedList();
                else if(x==7) reportData();

            }while(x!=8);
        }

        else if(ch==3){
            break;
        }
    }

    return 0;
}
