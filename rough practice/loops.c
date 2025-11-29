#include <stdio.h>
int main (){
int n;
int sum=0;
scanf("%d", &n);


//1 + 2 - 3 + 4 - 5 + 6 ..... n = ??

    for ( int i = 0 ; i <=n; i++ ){

        if ( i%2!=0) {
            sum = sum +i;
        }
        else sum = sum - i ;

    }
printf("%d", sum);

    return 0;

}