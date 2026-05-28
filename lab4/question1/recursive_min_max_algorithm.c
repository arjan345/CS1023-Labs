#include <stdio.h>

int arr[10] = {10, 8, 9, 12, 6, 8, 11, 7, 5, 9};

int findmax(int n) {
    int maxOfSmallerArray;

    if (n == 1) {
        return arr[0];
    }

    maxOfSmallerArray = findmax(n - 1);

    if (arr[n - 1] > maxOfSmallerArray) {
        return arr[n - 1];
    } else {
        return maxOfSmallerArray;
    }
}

int findmin(int n) {
    int minOfSmallerArray;

    if (n == 1) {
        return arr[0];
    }

    minOfSmallerArray = findmin(n - 1);

    if (arr[n - 1] < minOfSmallerArray) {
        return arr[n - 1];
    } else {
        return minOfSmallerArray;
    }
}

int main() {
    printf("Maximum = %d\n", findmax(10));
    printf("Minimum = %d\n", findmin(10));

    return 0;
}