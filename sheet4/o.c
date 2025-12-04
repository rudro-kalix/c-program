#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    static char s[10000005];
    scanf("%s", s);

    long long freq[26] = {0};

    for (int i = 0; i < N; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        while (freq[i]--)
            putchar('a' + i);

    return 0;
}
