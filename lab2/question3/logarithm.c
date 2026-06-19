#include <stdio.h>

int main(void) {
    int a;
    int b;
    int inputB;
    int count = 0;
    int divresult = 1;

    printf("Enter the base a: ");
    scanf("%d", &a);

    printf("Enter the number b: ");
    scanf("%d", &b);

    inputB = b;

    if (a <= 1) {
        printf("The base must be greater than 1.\n");
        return 1;
    }

    while (b > 1 && divresult == 1) {
        if (b % a == 0) {
            b = b / a;
            count++;
        } else {
            divresult = 0;
        }
    }

    if (divresult == 1 && b == 1) {
        printf("log base %d of %d is %d\n", a, inputB, count);
    } else {
        printf("log base %d of %d is not a whole-number logarithm\n", a, inputB);
    }

    return 0;
}