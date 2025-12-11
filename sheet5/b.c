#include <stdio.h>

void printNumbers(int n) {
    for(int i = 1; i <= n; i++) {
        if(i > 1) printf(" ");
        printf("%d", i);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    printNumbers(N);
    return 0;
}
