#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LEN 5 // Defines a macro that replaces all LEN with 5. We can't use variable or constants with brace-initialization

int main()
{
    printf("\n=== Find The Size Of An Array ===\n\n"); 
   
    // Declarations
    int x[] = {1, 2, 3, 4, 5};
    // Print the size of x[] array in bytes
    printf("sizeof(x): %lu\n", sizeof(x)); 
    printf("sizeof(x[0]): %lu\n", sizeof(x[0])); 
    printf("sizeof(int): %lu\n", sizeof(int)); // Same as the size of first x[0] element
    printf("array length: %lu\n", sizeof(x) / sizeof(x[0])); 

    int8_t y[] = {1, 2, 3, 4, 5};
    printf("sizeof(y): %lu\n", sizeof(y)); 
    printf("sizeof(y[0]): %lu\n", sizeof(y[0])); 
    printf("sizeof(int8_t): %lu\n", sizeof(int8_t)); 
    printf("array length: %lu\n", sizeof(y) / sizeof(y[0])); 

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
