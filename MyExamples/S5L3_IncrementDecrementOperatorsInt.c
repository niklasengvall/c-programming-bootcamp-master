#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;

    a = 0;
    b = a++; // b = 0, a = 1

    printf("After post increment:\n");
    printf("a: %d\n", a); // prints a: 1
    printf("b: %d\n\n", b); // prints b: 0

    a = 0;
    b = ++a; // b = 1, a = 1
    
    printf("After pre increment:\n");
    printf("a: %d\n", a); // prints a: 1
    printf("b: %d\n", b); // prints b: 1

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}