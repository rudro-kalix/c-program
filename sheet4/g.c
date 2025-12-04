#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100005];
    scanf("%s", s);

    for (int i = 0; s[i]; i++) {
        if (s[i] == ',')
            s[i] = ' ';
        else if (islower(s[i]))
            s[i] = toupper(s[i]);
        else if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }

    printf("%s\n", s);
    return 0;
}
