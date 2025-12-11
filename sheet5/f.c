#include <stdio.h>

long long power(int x, int p) {
    long long r = 1;
    for (int i = 0; i < p; i++) r *= x;
    return r;
}

long long solve(int x, int n) {
    long long s = 0;
    for (int i = 0; i <= n; i += 2) {
        if (i == 0) s += (power(x, 0) - 1);
        else s += power(x, i);
    }
    return s;
}

int main() {
    int X, N;
    scanf("%d %d", &X, &N);
    printf("%lld", solve(X, N));
    return 0;
}
//directsub