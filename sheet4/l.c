#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    static char s[2000005];   // VERY SAFE SIZE
    scanf("%s", s);

    int len = strlen(s);

    while (Q--) {
        char op[20];
        scanf("%s", op);

        if (!strcmp(op, "pop_back")) {
            if (len > 0) s[--len] = '\0';
        }

        else if (!strcmp(op, "front")) {
            printf("%c\n", s[0]);
        }

        else if (!strcmp(op, "back")) {
            printf("%c\n", s[len - 1]);
        }

        else if (!strcmp(op, "sort")) {
            int l, r;
            scanf("%d %d", &l, &r);
            qsort(s + (l - 1), r - l + 1, sizeof(char), cmp);
        }

        else if (!strcmp(op, "reverse")) {
            int l, r;
            scanf("%d %d", &l, &r);
            int i = l - 1, j = r - 1;
            while (i < j) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
            }
        }

        else if (!strcmp(op, "print")) {
            int pos;
            scanf("%d", &pos);
            printf("%c\n", s[pos - 1]);
        }

        else if (!strcmp(op, "substr")) {
            int l, r;
            scanf("%d %d", &l, &r);
            for (int i = l - 1; i <= r - 1; i++)
                putchar(s[i]);
            putchar('\n');
        }

        else if (!strcmp(op, "push_back")) {
            char c;
            s
