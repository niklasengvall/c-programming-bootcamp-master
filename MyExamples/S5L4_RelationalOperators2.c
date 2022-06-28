#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = 'a', b = 'z';

    printf("A = %c\n", a);
    printf("B = %c\n\n", b);
    
    printf("A == B --> %d\n", a == b);
    printf("A != B --> %d\n", a != b);
    printf("A > B --> %d\n", a > b);
    printf("A < B --> %d\n", a < b);
    printf("A >= B --> %d\n", a >= b);
    printf("A <= B --> %d\n", a <= b);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}