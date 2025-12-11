#include <stdio.h>

void findMinMax(int n, int a[], int *mn, int *mx) {
    *mn = a[0];
    *mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < *mn) *mn = a[i];
        if (a[i] > *mx) *mx = a[i];
    }
}

int main() {
    int n, a[1000], mn, mx;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    findMinMax(n, a, &mn, &mx);
    printf("%d %d", mn, mx);
    return 0;
}
