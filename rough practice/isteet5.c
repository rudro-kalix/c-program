#include <stidio.h>

void s_r( int a[][], int n, int x, int y ){
for (int j =0; j< n; j++){
int temp = a [x] [j];
a [x] [j]= a[y][j];
a[y][j] = temp;

}
}
void s_c( int a[][], int n, int x, int y ){
for (int i =0; i< n; i++){
int temp = a [i] [x];
a [i] [x]= a[i][y];
a[i][y] = temp;
}
}


int main () {
int n, x, y ;

scanf( "%d %d %d", &n, &x, &y);

x--;
y--;

int a[][];

for( int i= 0 ; i <n ; i++)
for ( int j= 0; j<n ; j++)

scanf("%d", &a[i][j]);
s_r(a,n,x,y);
s_c(a,n,x,y);





}