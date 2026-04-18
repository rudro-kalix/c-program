#include <stdio.h>
int main (){

    int arr[4];

    //we will take input of 5 students and then we will print the output of the marks which are less than 33

    for (int i=0; i <=4 ; i++){

        printf("Enter the Marks of student number %d :", i+1);
        scanf("%d", &arr[i]);

    }
int p=0, f=0;
    for( int i=0; i <=4; i ++){

        if (arr[i]>33){
            p++;
            printf("Passed sudent number is %d and his mark:%d \n",i+1,arr[i]);
        }

        else if(arr[i]<33) { f++; }

    }

printf("total passed: %d\n",p);
printf("total failed: %d",f);


    return 0;
}