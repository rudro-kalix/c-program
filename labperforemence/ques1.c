#include <stdio.h>
int main(){
    
    int arr[10]={11,23,33,44,55,56};
    int n=6, i, pos=3,value=77;

for (i=n; i >=pos ; i--){

    arr[i]=arr[i-1];

}
arr[pos-1] = value ;
n++;

printf("Array after insertion:\n");
for ( i = 0; i <n; i++){
    printf("%d ", arr[i]);
}

int del = 44,indx= -1;

for (int i = 0; i<n; i ++){

    if ( arr[i]==del){
        indx=i;
        break;
    }
}

if (indx!=-1){
    for(i=indx; i < n-1; i++){
        arr[i]= arr[i+1];
        }
        n--;
}
printf("\nArray after deleting 44:\n");

for(i=0; i<n;i++){
printf("%d ", arr[i]);

}

    return 0;

}