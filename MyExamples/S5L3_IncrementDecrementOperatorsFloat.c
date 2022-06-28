#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a, b;

    a = 3.14f;
    b = a++; // b = 0, a = 1

    printf("After post increment:\n");
    printf("a: %.2f\n", a); // prints a: 1
    printf("b: %.2f\n\n", b); // prints b: 0

    a = 3.14f;
    b = ++a; // b = 1, a = 1
    
    printf("After pre increment:\n");
    printf("a: %.2f\n", a); // prints a: 1
    printf("b: %.2f\n", b); // prints b: 1

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
