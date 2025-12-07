#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    scanf("%s", s);

    int n = strlen(s);
    for (int i = 0; i < n; ) {
        if (i + 5 <= n && strncmp(&s[i], "EGYPT", 5) == 0) {
            putchar(' ');
            i += 5;
        } else {
            putchar(s[i]);
            i++;
        }
    }

    return 0;
}
