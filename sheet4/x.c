#include <stdio.h>
#include <string.h>

int main() {
    char s[10005];
    if (scanf("%s", s) != 1) return 0;

    int n = strlen(s);
    if (n == 1) {
        printf("%s\n", s);
        return 0;
    }

    int total[26] = {0};
    for (int i = 0; i < n; i++)
        total[s[i] - 'a']++;

    static int pref[10005][26];
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++)
            pref[i][c] = pref[i - 1][c];
        pref[i][s[i - 1] - 'a']++;
    }

    char best[10005] = "";
    int first = 1;

    for (int split = 1; split < n; split++) {
        int left[26], right[26];
        for (int c = 0; c < 26; c++) {
            left[c] = pref[split][c];
            right[c] = total[c] - pref[split][c];
        }

        char cand[10005];
        int k = 0;
        for (int c = 0; c < 26; c++)
            while (left[c]--) cand[k++] = 'a' + c;
        for (int c = 0; c < 26; c++)
            while (right[c]--) cand[k++] = 'a' + c;
        cand[k] = '\0';

        if (first || strcmp(cand, best) < 0) {
            strcpy(best, cand);
            first = 0;
        }
    }

    printf("%s\n", best);
    return 0;
}
