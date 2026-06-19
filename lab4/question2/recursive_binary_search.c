#include <stdio.h>

int recursiveBinarySearch(const int arr[], int left, int right, int key);
void printArray(const int arr[], int size);

int main(void) {
    int values[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = (int)(sizeof(values) / sizeof(values[0]));
    int key;
    int result;

    printf("Sorted array: ");
    printArray(values, size);

    printf("Enter search key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    result = recursiveBinarySearch(values, 0, size - 1, key);

    if (result != -1) {
        printf("%d was found at index %d.\n", key, result);
    } else {
        printf("%d was not found in the array.\n", key);
    }

    return 0;
}

int recursiveBinarySearch(const int arr[], int left, int right, int key) {
    int mid;

    if (left > right) {
        return -1;
    }

    mid = left + (right - left) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    if (key < arr[mid]) {
        return recursiveBinarySearch(arr, left, mid - 1, key);
    }

    return recursiveBinarySearch(arr, mid + 1, right, key);
}

void printArray(const int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("\n");
}