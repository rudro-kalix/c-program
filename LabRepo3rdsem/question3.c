#include <stdio.h>

int arr[50] = {10, 20, 30, 40, 50, 60};
int n = 6;

void deleteAt(int pos) {
    int i;
    printf("Deleted: %d\n", arr[pos]);
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void display() {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Before: ");
    display();

    deleteAt(0);
    display();

    deleteAt(2);
    display();

    deleteAt(n - 1);
    display();

    return 0;
}