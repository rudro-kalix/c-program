#include <stdio.h>

int main (){

     int fst[10] = {12,12,32,34,5334,34,3443};

        int i = 0;

        for( int j = 6 ;  j>=0 ; j--){
            i++;
            fst[i]=fst[j];
            printf("%d \n", fst[i]);
        }



     


    return 0 ;
}