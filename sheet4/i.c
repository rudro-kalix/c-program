#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    scanf("%s", s);

    int n = strlen(s), ok = 1;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            ok = 0;

    printf(ok ? "YES\n" : "NO\n");
    return 0;
}
