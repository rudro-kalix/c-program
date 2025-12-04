#include <stdio.h>
#include <string.h>

int main() {
    char s[1000005];
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i]; i++) {
        if (s[i] == '\\') break;
        putchar(s[i]);
    }

    return 0;
}
