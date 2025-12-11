#include <stdio.h>

int main() {
    int r1,c1,r2,c2,i,j,k;
    int a[20][20],b[20][20],add[20][20],sub[20][20],mul[20][20];

    scanf("%d %d",&r1,&c1);
    for(i=0;i<r1;i++) for(j=0;j<c1;j++) scanf("%d",&a[i][j]);

    scanf("%d %d",&r2,&c2);
    for(i=0;i<r2;i++) for(j=0;j<c2;j++) scanf("%d",&b[i][j]);

    if(r1==r2 && c1==c2){
        for(i=0;i<r1;i++) for(j=0;j<c1;j++) add[i][j]=a[i][j]+b[i][j];
        for(i=0;i<r1;i++) for(j=0;j<c1;j++) sub[i][j]=a[i][j]-b[i][j];

        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++) printf("%d ",add[i][j]);
            printf("\n");
        }
        printf("\n");

        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++) printf("%d ",sub[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    if(c1==r2){
        for(i=0;i<r1;i++) for(j=0;j<c2;j++){
            mul[i][j]=0;
            for(k=0;k<c1;k++) mul[i][j]+=a[i][k]*b[k][j];
        }

        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++) printf("%d ",mul[i][j]);
            printf("\n");
        }
    }

    return 0;
}
