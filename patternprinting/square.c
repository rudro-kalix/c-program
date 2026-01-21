#include <stdio.h>

int main() {
int r,c;
printf ("Enter row: ");
scanf("%d", &r);
printf ("Enter col: ");
scanf("%d", &c);

for( int j =1; j <= c ; j++){
    for (int i=1; i <=r ; i++){
         printf("*");
    }
printf("\n");
}



    return 0;
}