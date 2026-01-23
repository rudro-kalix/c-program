#include<stdio.h>

int main(){
int v,i,j;
    printf("Enter value of triangle");
    scanf("%d",&v);

    for( i=1; i<=v; i++){
        for( j=1 ; j<=i; j++){
            printf("* ");
        }
printf("\n");
    }




    return 0;
}