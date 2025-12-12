#include <stdio.h>

int fact(int n){
    int i,f=1;
    for(i=1;i<=n;i++) f*=i;
    return f;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));
    return 0;
}
