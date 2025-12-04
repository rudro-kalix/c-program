#include <stdio.h>
#include <string.h>

int main() {
    char S[1005], T[1005];

    fgets(S, sizeof(S), stdin);
    fgets(T, sizeof(T), stdin);

    S[strcspn(S, "\n")] = '\0';
    T[strcspn(T, "\n")] = '\0';

    printf("%lu %lu\n", strlen(S), strlen(T));
    printf("%s %s\n", S, T);

    return 0;
}
