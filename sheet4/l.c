#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    static char s[2000005];
    getchar();                 // consume newline

    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    int len = strlen(s);

    while (Q--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "pop_back") == 0) {
            if (len > 0) s[--len] = '\0';
        }
        else if (strcmp(op, "front") == 0) {
            printf("%c\n", s[0]);
        }
        else if (strcmp(op, "back") == 0) {
            printf("%c\n", s[len - 1]);
        }
        else if (strcmp(op, "sort") == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            qsort(s + l - 1, r - l + 1, sizeof(char), cmp_char);
        }
        else if (strcmp(op, "reverse") == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            int i = l - 1, j = r - 1;
            while (i < j) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        else if (strcmp(op, "print") == 0) {
            int pos;
            scanf("%d", &pos);
            printf("%c\n", s[pos - 1]);
        }
        else if (strcmp(op, "substr") == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            for (int i = l - 1; i <= r - 1; i++)
                putchar(s[i]);
            putchar('\n');
        }
        else if (strcmp(op, "push_back") == 0) {
            char x;
            scanf(" %c", &x);
            s[len++] = x;
            s[len] = '\0';
        }
    }

    return 0;
}
//runtime error