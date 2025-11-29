#include <stdio.h>
int main (){
// !5= 5 x 4 x 3 x 2 x 1

int n;
int dig=1;
scanf("%d", &n);


    for ( int i = n; i >=1 ;i-- ){

        dig = dig * i;

    }


   printf("%d",dig);





    return 0;
}