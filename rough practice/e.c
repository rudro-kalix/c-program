#include <stdio.h>

void swap ( int x, int y){
    printf("%d %d", y,x);
}


int main (){

    int x, y;
    scanf ("%d %d",&x,&y);
    swap( x,y );



    return 0;
}