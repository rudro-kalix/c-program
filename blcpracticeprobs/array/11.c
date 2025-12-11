#include <stdio.h>
int main() {
    int r,c,i,j,a[100][100],sum;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) scanf("%d",&a[i][j]);
    for(j=0;j<c;j++){
        sum=0;
        for(i=0;i<r;i++) sum+=a[i][j];
        printf("%d\n",sum);
    }
}
