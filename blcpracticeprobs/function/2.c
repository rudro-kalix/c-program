#include <stdio.h>

int sum(int a[], int n){
    int i,s=0;
    for(i=0;i<n;i++) s+=a[i];
    return s;
}

int main(){
    int n,a[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d",sum(a,n));
    return 0;
}
