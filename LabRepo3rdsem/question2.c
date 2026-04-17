#include <stdio.h>

int arr[50];
int n = 0;

void insert(int value, int pos) {
    int i;
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
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
    insert(10, 0);
    insert(20, 1);
    insert(30, 2);
    insert(15, 1);
    insert(25, 3);

    display();

    return 0;
}