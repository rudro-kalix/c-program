#include <stdio.h>
#include <string.h>

int main() {
    char s[10005];
    scanf("%s", s);

    char target[] = "hello";
    int j = 0, n = strlen(s);

    for (int i = 0; i < n && j < 5; i++)
        if (s[i] == target[j])
            j++;

    if (j == 5) printf("YES\n");
    else printf("NO\n");

    return 0;
}
//ok