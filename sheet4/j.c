#include <stdio.h>
#include <string.h>

int main() {
    static char s[10000005];
    static long long freq[26];

    scanf("%s", s);

    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            printf("%c : %lld\n", 'a' + i, freq[i]);

    return 0;
}
