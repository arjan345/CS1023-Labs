#include <stdio.h>
#include <limits.h>

#define REQUIRED_UNSIGNED_INT_BITS 32

unsigned int packCharacters(
    unsigned char c1,
    unsigned char c2,
    unsigned char c3,
    unsigned char c4
);
void printByte(unsigned char value);
void printUnsignedIntBits(unsigned int value);

int main(void)
{
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned int packed;
    const int unsignedIntBits = (int)(sizeof(unsigned int) * CHAR_BIT);

    puts("Packing Four Characters");
    printf("unsigned int size on this system: %d bits\n", unsignedIntBits);

    if (unsignedIntBits < REQUIRED_UNSIGNED_INT_BITS) {
        puts("Error: unsigned int must contain at least 32 bits for this program.");
        return 1;
    }

    printf("Enter first character: ");
    scanf(" %c", &c1);

    printf("Enter second character: ");
    scanf(" %c", &c2);

    printf("Enter third character: ");
    scanf(" %c", &c3);

    printf("Enter fourth character: ");
    scanf(" %c", &c4);

    puts("\nCharacters before packing");
    printf("Character 1: '%c'  ASCII/byte value: %3u  bits: ", c1, c1);
    printByte(c1);
    printf("Character 2: '%c'  ASCII/byte value: %3u  bits: ", c2, c2);
    printByte(c2);
    printf("Character 3: '%c'  ASCII/byte value: %3u  bits: ", c3, c3);
    printByte(c3);
    printf("Character 4: '%c'  ASCII/byte value: %3u  bits: ", c4, c4);
    printByte(c4);

    packed = packCharacters(c1, c2, c3, c4);

    puts("\nPacked unsigned int result");
    printf("Decimal:     %u\n", packed);
    printf("Hexadecimal: 0x%08X\n", packed);
    printf("Binary:      ");
    printUnsignedIntBits(packed);

    return 0;
}

unsigned int packCharacters(
    unsigned char c1,
    unsigned char c2,
    unsigned char c3,
    unsigned char c4
)
{
    unsigned int packed = c1;

    packed <<= CHAR_BIT;
    packed |= c2;
    packed <<= CHAR_BIT;
    packed |= c3;
    packed <<= CHAR_BIT;
    packed |= c4;

    return packed;
}

void printByte(unsigned char value)
{
    unsigned char mask = (unsigned char)(1U << (CHAR_BIT - 1));
    int bit;

    for (bit = 1; bit <= CHAR_BIT; ++bit) {
        putchar((value & mask) ? '1' : '0');
        value = (unsigned char)(value << 1);
    }

    putchar('\n');
}

void printUnsignedIntBits(unsigned int value)
{
    const int totalBits = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int mask = 1U << (totalBits - 1);
    int bit;

    for (bit = 1; bit <= totalBits; ++bit) {
        putchar((value & mask) ? '1' : '0');
        value <<= 1;

        if (bit % CHAR_BIT == 0 && bit != totalBits) {
            putchar(' ');
        }
    }

    putchar('\n');
}