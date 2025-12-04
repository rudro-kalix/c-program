#include <stdio.h>
#include <string.h>

int main() {
    char A[20], B[20];
    scanf("%s %s", A, B);

    printf("%lu %lu\n", strlen(A), strlen(B));

    printf("%s%s\n", A, B);

    char temp = A[0];
    A[0] = B[0];
    B[0] = temp;

    printf("%s %s\n", A, B);

    return 0;
}
