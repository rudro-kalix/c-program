#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char s[55], t[55];
        scanf("%s %s", s, t);

        int i = 0, ls = strlen(s), lt = strlen(t);
        while (i < ls || i < lt) {
            if (i < ls) putchar(s[i]);
            if (i < lt) putchar(t[i]);
            i++;
        }
        putchar('\n');
    }

    return 0;
}
