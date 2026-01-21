#include <stdio.h>

int main (){
int v,r;
 printf("enter row : ");
 scanf("%d",&r);
    printf("enter a value : ");
    scanf("%d",&v);
 
    for (int i=1; i<=r; i++);{
        for(int j=1;j<=v;j++){
            printf("%d",j);
        }
printf("\n");

    }



    return 0;
}