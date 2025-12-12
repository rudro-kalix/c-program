#include <stdio.h>

void maxmin(int a[], int n){
    int i,max=a[0],min=a[0];
    for(i=1;i<n;i++){
        if(a[i]>max) max=a[i];
        if(a[i]<min) min=a[i];
    }
    printf("%d %d",max,min);
}

int main(){
    int n,a[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    maxmin(a,n);
    return 0;
}
