#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void clear_Input_Buffer(void);
double *create_Scores(size_t count);
void read_Scores(double scores[], size_t count);
void print_Scores(const double scores[], size_t count);
double find_Minimum(const double scores[], size_t count);
double find_Maximum(const double scores[], size_t count);
double calculate_Average(const double scores[], size_t count);

void clear_Input_Buffer(void)  
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        
    }
}

double *create_Scores(size_t count)
{
    return malloc(count * sizeof(double));
}

void read_Scores(double scores[], size_t count)
{
    for (size_t i = 0; i < count; i++) {
        int valid_Input = 0;

        while (!valid_Input) {
            printf("Enter score %zu: ", i + 1);

            if (scanf("%lf", &scores[i]) == 1) {
                valid_Input = 1;
            } else {
                printf("Invalid score!!!!! Please enter a numeric value.\n");
                clear_Input_Buffer();
            }
        }
    }
}

void print_Scores(const double scores[], size_t count)
{
    printf("\nScores entered:\n");
    for (size_t i = 0; i < count; i++) {
        printf("Score %zu: %.2f\n", i + 1, scores[i]);
    }
}

double find_Minimum(const double scores[], size_t count)
{
    double minimum = scores[0];

    for (size_t i = 1; i < count; i++) {
        if (scores[i] < minimum) {
            minimum = scores[i];
        }
    }

    return minimum;
}

double find_Maximum(const double scores[], size_t count)
{
    double maximum = scores[0];

    for (size_t i = 1; i < count; i++) {
        if (scores[i] > maximum) {
            maximum = scores[i];
        }
    }

    return maximum;
}

double calculate_Average(const double scores[], size_t count)
{
    double total = 0.0;

    for (size_t i = 0; i < count; i++) {
        total += scores[i];
    }

    return total / (double) count;
}

int main(void)
{
    long requested_Count;
    double *scores = NULL;

    printf("Dynamic Scores Program\n");
    printf("How many scores you want to enter? ");

    if (scanf("%ld", &requested_Count) != 1) {
        printf("Error! the number of scores must be an integer.\n");
        return 1;
    }

    if (requested_Count <= 0) {
        printf("Error! the number of scores must be greater than zero.\n");
        return 1;
    }

    scores = create_Scores((size_t) requested_Count);
    if (scores == NULL) {
        printf("Error! memory allocation didn't work.\n");
        return 1;
    }

    read_Scores(scores, (size_t) requested_Count);
    print_Scores(scores, (size_t) requested_Count);

    printf("\nMinimum score: %.2f\n", find_Minimum(scores, (size_t) requested_Count));
    printf("Maximum score: %.2f\n", find_Maximum(scores, (size_t) requested_Count));
    printf("Average score: %.2f\n", calculate_Average(scores, (size_t) requested_Count));

    free(scores);
    scores = NULL;

    printf("\nMemory released. Program finished.\n");

    return 0;
}
