#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char s[100005];
        scanf("%s", s);

        int n = strlen(s), good = 0;
        for (int i = 0; i + 2 < n; i++) {
            if ((s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') ||
                (s[i] == '1' && s[i+1] == '0' && s[i+2] == '1')) {
                good = 1;
                break;
            }
        }

        if (good) printf("Good\n");
        else printf("Bad\n");
    }

    return 0;
}
