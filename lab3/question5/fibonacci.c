#include <stdio.h>

unsigned long long int fibonacci(int n);

int main(void) {
    int n;
    int result;
    unsigned long long int value;

    printf("Enter n: ");
    result = scanf("%d", &n);

    if (result != 1) {
        printf("Error: please enter a valid integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: n must be 0 or greater.\n");
        return 1;
    }

    value = fibonacci(n);

    printf("Fibonacci(%d) = %llu\n", n, value);

    if (n > 93) {
        printf("Warning: values above n = 93 overflow unsigned long long int.\n");
    }

    return 0;
}

unsigned long long int fibonacci(int n) {
    unsigned long long int previous_n = 0;
    unsigned long long int current_n = 1;
    unsigned long long int next;
    int i;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    for (i = 2; i <= n; i++) {
        next = previous_n + current_n;
        previous_n = current_n;
        current_n = next;
    }

    return current_n;
}