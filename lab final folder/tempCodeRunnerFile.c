#include <stdio.h>
#define mx_size 100
void fls(char arr[], int size, char *lar, char *sma) {

 if (n <= 0) return;
    *lar = *sma = arr[0];
    for ( int i = 1; i < size; ++i){
        if( arr[i]<*sma) *sma=arr[i];
        if(arr[i] > *lar) *lar=arr[i];

    }
}
int main (){

char arr[100];
int n;
if(scanf("%d", &n)!=1 || n <= 0 || n > 100){

    return 0;
    }

    for ( int i = 0 ; i < n; ++i){

        scanf("%c", &arr[i]);

    }

char lar, sma;
fls (arr, n, &lar, &sma);
printf("%c ",&lar);
printf("%c ",&sma);
return 0;

}