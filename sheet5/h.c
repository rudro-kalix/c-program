#include <stdio.h>

void printChar(int n, char c) {
    for (int i = 1; i <= n; i++) {
        printf("%c", c);
        if (i < n) printf(" ");
    }
}

int main() {
    int T, N;
    char C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %c", &N, &C);
        printChar(N, C);
        if (T) printf("\n");
    }
    return 0;
}
//directsub