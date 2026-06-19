#include <stdio.h>

int main(void) {
    int num;
    int digit_1;
    int digit_2;
    int digit_3;
    int digit_4;
    int digit_5;

    printf("Enter a five-digit integer: ");
    scanf("%d", &num);

    digit_1 = num / 10000;
    digit_2 = (num / 1000) % 10;
    digit_3 = (num / 100) % 10;
    digit_4 = (num / 10) % 10;
    digit_5 = num % 10;

    printf("%d   %d   %d   %d   %d\n", digit_1, digit_2, digit_3, digit_4, digit_5);

    return 0;
}