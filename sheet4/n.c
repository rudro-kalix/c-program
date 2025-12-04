#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[100005];
    scanf("%s", s);

    int ans = 1;
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            ans++;

    printf("%d\n", ans);
    return 0;
}
