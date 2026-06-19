#include <stdio.h>

void productExceptSelf(const int nums[], int answer[], int size);
void printArray(const int nums[], int size);

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int size = (int)(sizeof(nums) / sizeof(nums[0]));
    int answer[4];

    productExceptSelf(nums, answer, size);

    printf("Input array:  ");
    printArray(nums, size);

    printf("Output array: ");
    printArray(answer, size);

    return 0;
}

void productExceptSelf(const int nums[], int answer[], int size) {
    int i;
    int leftProduct = 1;
    int rightProduct = 1;

    for (i = 0; i < size; i++) {
        answer[i] = leftProduct;
        leftProduct = leftProduct * nums[i];
    }

    for (i = size - 1; i >= 0; i--) {
        answer[i] = answer[i] * rightProduct;
        rightProduct = rightProduct * nums[i];
    }
}

void printArray(const int nums[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", nums[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("\n");
}