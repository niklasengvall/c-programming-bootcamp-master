#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    bool a = true;  // Declare and initialize a boolean value
    bool b = false; // The compiler translates this to an integer value

    printf("a (true):   %d\n", a);
    printf("b (false):  %d\n", b);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}