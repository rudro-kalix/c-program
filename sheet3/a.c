#include<stdio.h>
 
int main(){
    int n;
    scanf("%d", &n);
    long long arr[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        sum = sum + arr[i];
    }
    printf("%lld\n", (sum < 0) ? -1 * sum : sum);
    return 0;
}
aaaa