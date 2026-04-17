#include <stdio.h>
int main (){

    int arr[]= {20,80,25,70,15},n=5 ,s=75, i,f=0;


    for ( i= 0; i<n; i++){
        if (arr[i]==s){

            f=1;
            break;

        }

    }

    if(f){

        printf("product found at position %d", i+1);
    }


    else
     printf("product not found");

    return 0;
}