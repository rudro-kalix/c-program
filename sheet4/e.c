#include <stdio.h>
#include <string.h>

int main() {
    char s[1000005];
    scanf("%s", s);

    long long sum = 0;
    for (int i = 0; s[i]; i++)
        sum += s[i] - '0';

    printf("%lld\n", sum);
    return 0;
}
