#include <stdio.h>
#include <string.h>

int main() {
    char x[25], y[25];

    scanf("%24s %24s", x, y);

    if (strcmp(x, y) <= 0)
        printf("%s\n", x);
    else
        printf("%s\n", y);

    return 0;
}
