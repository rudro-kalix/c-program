#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    swap(&X, &Y);
    printf("%d %d", X, Y);
    return 0;
}
//directsub