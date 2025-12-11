#include <stdio.h>

int isPalindrome(unsigned int n) {
    unsigned int rev = 0, temp = n;
    while (temp > 0) {
        rev = (rev << 1) | (temp & 1);
        temp >>= 1;
    }
    return rev == n;
}

int isWonderful(unsigned int n) {
    if (n % 2 == 0) return 0;
    return isPalindrome(n);
}

int main() {
    unsigned int N;
    scanf("%u", &N);
    if (isWonderful(N)) printf("YES");
    else printf("NO");
    return 0;
}
