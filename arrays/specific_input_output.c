#include <stdio.h>
int main (){

    int arr[5];

    //we will take input of 5 students and then we will print the output of the marks which are less than 33

    for (int i=0; i <=4 ; i++){

        printf("Enter the Marks of student number %d :", i+1);
        scanf("%d", &arr[i]);

    }
int p=1, f=1;
    for( int i=0; i <=5; i ++){

        if (arr[i]>33){

            printf("Passed sudent number is %d and his mark:%d \n",i+1,arr[i]);
            p++;
        }

        else f++;

    }

printf("total passed: %d",p);
printf("total failed: %d",f);
    return 0;
}