#include <stdio.h>

int summation(int a, int b) {
    return a + b;
}

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    printf("%d\n", summation(X, Y));
    return 0;
}
