#include <stdio.h>

int a[500][500];

void swapRows(int n, int x, int y) {
    for (int j = 0; j < n; j++) {
        int t = a[x][j];
        a[x][j] = a[y][j];
        a[y][j] = t;
    }
}

void swapCols(int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        int t = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = t;
    }
}

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    x--; 
    y--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    swapRows(n, x, y);
    swapCols(n, x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
            if (j < n - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }

    return 0;
}
