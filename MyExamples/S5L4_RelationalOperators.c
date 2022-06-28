#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;

    printf("Enter operand A (int): ");
    scanf("%d", &a);

    printf("Enter operand B (int): ");
    scanf("%d", &b);

    printf("A == B --> %d\n", a == b);
    printf("A != B --> %d\n", a != b);
    printf("A > B --> %d\n", a > b);
    printf("A < B --> %d\n", a < b);
    printf("A >= B --> %d\n", a >= b);
    printf("A <= B --> %d\n", a <= b);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}