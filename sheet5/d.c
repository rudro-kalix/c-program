#include <stdio.h>

int isPrime(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int T;
    long long N;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        if (isPrime(N)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
