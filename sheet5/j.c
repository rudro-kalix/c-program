#include <stdio.h>

double average(int n, double a[]) {
    double s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s / n;
}

int main() {
    int n;
    double a[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    printf("%.6f", average(n, a));
    return 0;
}
