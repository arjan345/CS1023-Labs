#include <stdio.h>
#include <limits.h>

#define shift_number 3

void printBits(unsigned int value);
void printLeadingBits(unsigned int value, int count);

int main(void)
{
    int value;
    int shifted;
    int result;

    puts("Right-Shifting an Integer");
    printf("Enter an integer: ");
    result = scanf("%d", &value);

    if (result != 1) {
        puts("Invalid input. Please enter an integer.");
        return 1;
    }

    shifted = value >> shift_number;

    printf("\nOriginal decimal value: %d\n", value);
    printf("Original binary value : ");
    printBits((unsigned int)value);

    printf("\nShift operation: %d >> %d\n", value, shift_number);

    printf("\nShifted decimal value : %d\n", shifted);
    printf("Shifted binary value  : ");
    printBits((unsigned int)shifted);

    printf("\nThe right shift vacated the %d leftmost bit positions.\n",shift_number);
    printf("On this system, the new leftmost %d bits are: ", shift_number);
    printLeadingBits((unsigned int)shifted, shift_number);
    putchar('\n');

    return 0;
}

void printBits(unsigned int value)
{
    const int totalBits = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int mask = 1U << (totalBits - 1);
    int bit;

    for (bit = 1; bit <= totalBits; ++bit) {
        putchar((value & mask) ? '1' : '0');
        value <<= 1;

        if (bit % 8 == 0 && bit != totalBits) {
            putchar(' ');
        }
    }

    putchar('\n');
}

void printLeadingBits(unsigned int value, int count)
{
    const int totalBits = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int mask = 1U << (totalBits - 1);
    int bit;

    for (bit = 0; bit < count; ++bit) {
        putchar((value & mask) ? '1' : '0');
        value <<= 1;
    }
}