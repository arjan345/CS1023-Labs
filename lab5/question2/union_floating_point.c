#include <stdio.h>
#include <stdlib.h>

union floatingPoint {
    float f;
    double d;
    long double x;
};

static void clearInputBuffer(void);
static float readFloat(const char *prompt);
static double readDouble(const char *prompt);
static long double readLongDouble(const char *prompt);
static void printUnionValues(const char *label, union floatingPoint value, const char *lastMember);

int main(void)
{
    union floatingPoint value1;
    union floatingPoint value2;
    union floatingPoint value3;

    puts("Investigating a Union");

    value1.f = readFloat("Enter a float value: ");
    value2.d = readDouble("Enter a double value: ");
    value3.x = readLongDouble("Enter a long double value: ");

    puts("\nSizes on this system");
    printf("sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("sizeof(long double) = %zu bytes\n", sizeof(long double));
    printf("sizeof(union floatingPoint) = %zu bytes\n", sizeof(union floatingPoint));

    printUnionValues("Union variable 1", value1, "f");
    printUnionValues("Union variable 2", value2, "d");
    printUnionValues("Union variable 3", value3, "x");

    return 0;
}

static void printUnionValues(const char *label, union floatingPoint value, const char *lastMember)
{
    printf("\n%s\n", label);
    printf("Most recently assigned member: %s\n", lastMember);
    printf("Printed as float:       %.9g\n", value.f);
    printf("Printed as double:      %.17g\n", value.d);
    printf("Printed as long double: %.21Lg\n", value.x);
}

static float readFloat(const char *prompt)
{
    float value;
    int result;

    do {
        printf("%s", prompt);
        result = scanf("%f", &value);
        clearInputBuffer();

        if (result != 1) {
            puts("Invalid input. Please enter a float value.");
        }
    } while (result != 1);

    return value;
}

static double readDouble(const char *prompt)
{
    double value;
    int result;

    do {
        printf("%s", prompt);
        result = scanf("%lf", &value);
        clearInputBuffer();

        if (result != 1) {
            puts("Invalid input. Please enter a double value.");
        }
    } while (result != 1);

    return value;
}

static long double readLongDouble(const char *prompt)
{
    long double value;
    int result;

    do {
        printf("%s", prompt);
        result = scanf("%Lf", &value);
        clearInputBuffer();

        if (result != 1) {
            puts("Invalid input. Please enter a long double value.");
        }
    } while (result != 1);

    return value;
}

static void clearInputBuffer(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
        ;
    }
}