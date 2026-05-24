#include <stdio.h>

void cleanbuffer(void);

int main() {
    int grade;
    int result;
    int first;
    int second;

    printf("Enter one integer grade: ");
    result = scanf("%d", &grade);

    printf("scanf return value: %d\n", result);

    if (result == 1) {
        printf("Input successful. Grade = %d\n", grade);
    } else {
        printf("Error: the input was not a valid integer grade.\n");
    }

    cleanbuffer();

    printf("\nEnter two integers separated by a space: ");
    result = scanf("%d %d", &first, &second);

    printf("scanf return value: %d\n", result);

    if (result == 2) {
        printf("Both values were read successfully: %d and %d\n", first, second);
    } else if (result == 1) {
        printf("Only one integer was read successfully: %d\n", first);
    } else {
        printf("Error: no integers were read successfully.\n");
    }

    return 0;
}

void cleanbuffer(void) {
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
        ;
    }
}
