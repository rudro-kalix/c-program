#include <stdio.h>
#include <string.h>

int main() {
    static char s[1000005];
    fgets(s, sizeof(s), stdin);

    int n = strlen(s), i = 0;

    while (i < n) {
        if (s[i] == ' ') {
            putchar(' ');
            i++;
        } else {
            int start = i;
            while (i < n && s[i] != ' ' && s[i] != '\n') i++;
            int end = i - 1;
            while (end >= start) {
                putchar(s[end]);
                end--;
            }
        }
    }

    return 0;
}
