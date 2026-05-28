#include <stdio.h>

void sortColors(int nums[], int size);
void printArr(const int nums[], int size);

int main(void) {
    int colors[] = {2, 0, 2, 1, 1, 0, 2, 0, 1};
    int size = (int)(sizeof(colors) / sizeof(colors[0]));

    printf("Before sorting: ");
    printArr(colors, size);

    sortColors(colors, size);

    printf("After sorting:  ");
    printArr(colors, size);

    return 0;
}

void sortColors(int nums[], int size) {
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int i;
    int index = 0;

    for (i = 0; i < size; i++) {
        if (nums[i] == 0) {
            count0++;
        } else if (nums[i] == 1) {
            count1++;
        } else if (nums[i] == 2) {
            count2++;
        }
    }

    for (i = 0; i < count0; i++) {
        nums[index] = 0;
        index++;
    }

    for (i = 0; i < count1; i++) {
        nums[index] = 1;
        index++;
    }

    for (i = 0; i < count2; i++) {
        nums[index] = 2;
        index++;
    }
}

void printArr(const int nums[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", nums[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("\n");
}