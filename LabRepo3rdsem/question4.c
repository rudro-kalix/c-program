#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int n, int key) {
    int i;
    printf("\nUnsorted Array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nSearching %d using Linear Search...\n", key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found.\n");
}

void binarySearch(int arr[], int n, int key) {
    int i, low, high, mid;
    bubbleSort(arr, n);
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nSearching %d using Binary Search...\n", key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Found at index %d\n", mid);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Not found.\n");
}

int main() {
    int arr1[] = {64, 25, 12, 45, 78, 33};
    int arr2[] = {64, 25, 12, 45, 78, 33};
    int n = 6;
    int key = 45;

    linearSearch(arr1, n, key);
    binarySearch(arr2, n, key);

    return 0;
}