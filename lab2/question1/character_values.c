#include <stdio.h>

int main() {
    printf("Character    Integer value\n");
    printf("%-10c %d\n", 'A', 'A');
    printf("%-10c %d\n", 'B', 'B');
    printf("%-10c %d\n", 'C', 'C');
    printf("%-10c %d\n", 'a', 'a');
    printf("%-10c %d\n", 'b', 'b');
    printf("%-10c %d\n", 'c', 'c');
    printf("%-10c %d\n", '0', '0');
    printf("%-10c %d\n", '1', '1');
    printf("%-10c %d\n", '2', '2');
    printf("%-10c %d\n", '$', '$');
    printf("%-10c %d\n", '*', '*');
    printf("%-10c %d\n", '+', '+');
    printf("%-10c %d\n", '/', '/');
    printf("%-10s %d\n", "space", ' ');

    return 0;
}