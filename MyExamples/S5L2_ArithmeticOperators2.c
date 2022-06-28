#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a, b, c;
    printf("Enter A operand (float): ");
    scanf("%f", &a);

    printf("Enter B operand (float): ");
    scanf("%f", &b);

    printf("\n");

    c = a + b;
    printf("c = a + b --> %9.3f\n", c);

    c = a - b;
    printf("c = a - b --> %9.3f\n", c);

    c = a * b;
    printf("c = a * b --> %9.3f\n", c);

    c = a / b;
    printf("c = a / b --> %9.3f\n", c);

    //c = a % b;
    //printf("c = a %% b --> %9.3f\n", c);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}