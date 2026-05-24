#include <stdio.h>

int toQualityPoints(int avg);

int main() {
    int avg;
    int result;
    int qpoints;

    printf("Enter student average: ");
    result = scanf("%d", &avg);

    if (result != 1) {
        printf("Error: please enter a valid integer average.\n");
        return 1;
    }

    qpoints = toQualityPoints(avg);

    printf("Average: %d\n", avg);
    printf("Quality points: %d\n", qpoints);

    return 0;
}

int toQualityPoints(int avg) {
    if (avg >= 90 && avg <= 100) {
        return 4;
    } else if (avg >= 80 && avg <= 89) {
        return 3;
    } else if (avg >= 70 && avg <= 79) {
        return 2;
    } else if (avg >= 60 && avg <= 69) {
        return 1;
    } else {
        return 0;
    }
}