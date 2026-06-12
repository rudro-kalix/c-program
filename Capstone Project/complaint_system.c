#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300
#define NM 60
#define TXT 200
#define DATA "complaints.dat"
#define PASS "admin.txt"

typedef struct {
    int id;
    char name[NM];
    char phone[30];
    char cat[40];
    char info[TXT];
    char stat[20];
} Complaint;

void cutnl(char s[])
{
    int n = strlen(s);

    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

void getstr(char msg[], char s[], int size)
{
    printf("%s", msg);
    fgets(s, size, stdin);
    cutnl(s);

    while (strlen(s) == 0) {
        printf("Enter again: ");
        fgets(s, size, stdin);
        cutnl(s);
    }
}

int getnum(char msg[])
{
    char s[30];
    int x;

    printf("%s", msg);
    fgets(s, sizeof(s), stdin);

    while (sscanf(s, "%d", &x) != 1) {
        printf("Enter number: ");
        fgets(s, sizeof(s), stdin);
    }

    return x;
}

void wait()
{
    char s[5];

    printf("\nPress Enter...");
    fgets(s, sizeof(s), stdin);
}

int load(Complaint a[])
{
    FILE *fp;
    int n;

    fp = fopen(DATA, "rb");
    if (fp == NULL) {
        return 0;
    }

    fread(&n, sizeof(int), 1, fp);

    if (n < 0 || n > MAX) {
        fclose(fp);
        return 0;
    }

    fread(a, sizeof(Complaint), n, fp);
    fclose(fp);

    return n;
}

void save(Complaint a[], int n)
{
    FILE *fp;

    fp = fopen(DATA, "wb");
    if (fp == NULL) {
        printf("File save failed.\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, fp);
    fwrite(a, sizeof(Complaint), n, fp);
    fclose(fp);
}

int nextid(Complaint a[], int n)
{
    int i;
    int big = 1000;

    for (i = 0; i < n; i++) {
        if (a[i].id > big) {
            big = a[i].id;
        }
    }

    return big + 1;
}

int find(Complaint a[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++) {
        if (a[i].id == id) {
            return i;
        }
    }

    return -1;
}

void show(Complaint *c)
{
    printf("\n-----------------------------\n");
    printf("ID: %d\n", c->id);
    printf("Name: %s\n", c->name);
    printf("Phone: %s\n", c->phone);
    printf("Category: %s\n", c->cat);
    printf("Details: %s\n", c->info);
    printf("Status: %s\n", c->stat);
}

void add(Complaint a[], int *n)
{
    Complaint c;

    if (*n >= MAX) {
        printf("No space left.\n");
        return;
    }

    c.id = nextid(a, *n);

    getstr("Name: ", c.name, NM);
    getstr("Phone: ", c.phone, sizeof(c.phone));
    getstr("Category: ", c.cat, sizeof(c.cat));
    getstr("Problem details: ", c.info, TXT);

    strcpy(c.stat, "Pending");

    a[*n] = c;
    (*n)++;

    save(a, *n);

    printf("\nComplaint added.\n");
    printf("Complaint ID: %d\n", c.id);
}

void check(Complaint a[], int n)
{
    int id;
    int p;

    id = getnum("Complaint ID: ");
    p = find(a, n, id);

    if (p == -1) {
        printf("Not found.\n");
    } else {
        show(&a[p]);
    }
}

void showall(Complaint a[], int n)
{
    int i;

    if (n == 0) {
        printf("No complaint found.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        show(&a[i]);
    }
}

void search(Complaint a[], int n)
{
    char key[60];
    int i;
    int id;
    int ok = 0;

    getstr("Search: ", key, sizeof(key));
    id = atoi(key);

    for (i = 0; i < n; i++) {
        if (a[i].id == id ||
            strcmp(a[i].name, key) == 0 ||
            strcmp(a[i].phone, key) == 0 ||
            strcmp(a[i].cat, key) == 0 ||
            strcmp(a[i].stat, key) == 0) {
            show(&a[i]);
            ok = 1;
        }
    }

    if (ok == 0) {
        printf("No match found.\n");
    }
}

void status(Complaint a[], int n)
{
    int id;
    int p;
    int ch;

    id = getnum("Complaint ID: ");
    p = find(a, n, id);

    if (p == -1) {
        printf("Not found.\n");
        return;
    }

    printf("\n1. Pending\n");
    printf("2. In Progress\n");
    printf("3. Solved\n");
    printf("4. Rejected\n");

    ch = getnum("Choice: ");

    switch (ch) {
        case 1:
            strcpy(a[p].stat, "Pending");
            break;
        case 2:
            strcpy(a[p].stat, "In Progress");
            break;
        case 3:
            strcpy(a[p].stat, "Solved");
            break;
        case 4:
            strcpy(a[p].stat, "Rejected");
            break;
        default:
            printf("Wrong choice.\n");
            return;
    }

    save(a, n);
    printf("Status changed.\n");
}

void del(Complaint a[], int *n)
{
    int id;
    int p;
    int i;

    id = getnum("Delete ID: ");
    p = find(a, *n, id);

    if (p == -1) {
        printf("Not found.\n");
        return;
    }

    for (i = p; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;
    save(a, *n);
    printf("Deleted.\n");
}

void showstat(Complaint a[], int n, char st[])
{
    int i;
    int ok = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(a[i].stat, st) == 0) {
            show(&a[i]);
            ok = 1;
        }
    }

    if (ok == 0) {
        printf("No %s complaint found.\n", st);
    }
}

int login()
{
    FILE *fp;
    char pass[30] = "admin123";
    char in[30];

    fp = fopen(PASS, "r");

    if (fp == NULL) {
        fp = fopen(PASS, "w");
        if (fp != NULL) {
            fprintf(fp, "admin123\n");
            fclose(fp);
        }
    } else {
        fscanf(fp, "%29s", pass);
        fclose(fp);
    }

    getstr("Admin password: ", in, sizeof(in));

    if (strcmp(in, pass) == 0) {
        return 1;
    }

    printf("Wrong password.\n");
    return 0;
}

void usermenu(Complaint a[], int *n)
{
    int ch;

    do {
        printf("\nUser Menu\n");
        printf("1. Add Complaint\n");
        printf("2. Check Status\n");
        printf("0. Back\n");

        ch = getnum("Choice: ");

        switch (ch) {
            case 1:
                add(a, n);
                wait();
                break;
            case 2:
                check(a, *n);
                wait();
                break;
            case 0:
                break;
            default:
                printf("Wrong choice.\n");
                wait();
        }
    } while (ch != 0);
}

void adminmenu(Complaint a[], int *n)
{
    int ch;

    if (login() == 0) {
        return;
    }

    do {
        printf("\nAdmin Menu\n");
        printf("1. Add Complaint\n");
        printf("2. View All\n");
        printf("3. Search\n");
        printf("4. Update Status\n");
        printf("5. Delete\n");
        printf("6. Pending Complaints\n");
        printf("7. Solved Complaints\n");
        printf("0. Back\n");

        ch = getnum("Choice: ");

        switch (ch) {
            case 1:
                add(a, n);
                wait();
                break;
            case 2:
                showall(a, *n);
                wait();
                break;
            case 3:
                search(a, *n);
                wait();
                break;
            case 4:
                status(a, *n);
                wait();
                break;
            case 5:
                del(a, n);
                wait();
                break;
            case 6:
                showstat(a, *n, "Pending");
                wait();
                break;
            case 7:
                showstat(a, *n, "Solved");
                wait();
                break;
            case 0:
                break;
            default:
                printf("Wrong choice.\n");
                wait();
        }
    } while (ch != 0);
}

int main()
{
    Complaint *a;
    int n;
    int ch;

    a = (Complaint *) malloc(MAX * sizeof(Complaint));

    if (a == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    n = load(a);

    do {
        printf("\nComplaint Management System\n");
        printf("1. User\n");
        printf("2. Admin\n");
        printf("0. Exit\n");

        ch = getnum("Choice: ");

        switch (ch) {
            case 1:
                usermenu(a, &n);
                break;
            case 2:
                adminmenu(a, &n);
                break;
            case 0:
                save(a, n);
                printf("Saved. Bye.\n");
                break;
            default:
                printf("Wrong choice.\n");
        }
    } while (ch != 0);

    free(a);
    return 0;
}
