 
#include<stdio.h>
 
int main(){
    int n, index = -1;
    scanf("%d", &n);
    long long arr[n], x;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    scanf("%lld", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            index = i;
            break;
        }
    }
    printf("%d\n", index);
    return 0;
}

