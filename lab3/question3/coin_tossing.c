#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main(void) {
    int toss;
    int result;
    int count_heads = 0;
    int count_tails = 0;

    srand((unsigned int) time(NULL));

    for (toss = 1; toss <= 100; toss++) {
        result = flip();

        if (result == 1) {
            printf("Toss %3d: Heads\n", toss);
            count_heads++;
        } else {
            printf("Toss %3d: Tails\n", toss);
            count_tails++;
        }
    }

    printf("\nFinal results\n");
    printf("Heads: %d\n", count_heads);
    printf("Tails: %d\n", count_tails);

    return 0;
}

int flip(void) {
    return rand() % 2;
}