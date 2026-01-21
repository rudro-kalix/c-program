#include <stdio.h>

int main (){
int l;
 printf("enter number of lines : ");
 scanf("%d",&l);

 int num=1;
    for (int i=1; i<=l; i++){
       
        for(int j=1;j<=l;j++){
            printf("%d",num);
            num++;
        }

        printf("\n");
    }



    return 0;
}