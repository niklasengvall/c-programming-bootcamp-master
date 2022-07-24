#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{

    printf("\n=== Pointers and Arrays ===\n\n"); 
   
    // Declarations
    int x[] = {9, 8, 7, 6, 5};

    // Calulate no of elements in the array outsize the loop, saves us some time
    int arraySize = sizeof(x) / sizeof(x[0]);

    for (int i = 0; i < arraySize; i++)
    {
        printf("x[%d]: %d\n", i, x[i]);
    }

    /**
     * Lets recall:
     *  - an array is an ordered collection of items of the same type
     *  - a pointer holds the address of other data
     * 
     * Can we access the elements of an array through pointers? Yes!
     * 
     */

    printf("Access an element of x through the pointer:\n");
    int *p = &x[2];
    printf("x[2]: %d, *p: %d\n", x[2], *p); 
    
    // Change the value using pointer arithmetic
    *p = 0;
    printf("x[2]: %d, *p: %d\n", x[2], *p); 

    
    printf("Array start address:\n");
    printf("&x[0]: %016lX\n", (uint64_t) &x[0]); 
    printf("x:     %016lX\n", (uint64_t) x); 
    
    // How to make an alias to an array
    
    // int *alias = x; // or
    // int *alias = &x[0];

    p = x; // preferably we use this method to set a pointers address to an arrays start position

    printf("Display x through the pointer:\n"); 
    for (int i = 0; i < arraySize; i++)
    {
        printf("x[%d]: %d, p[%d]: %d\n", i, x[i], i, p[i]);
    }
    
    printf("Set x to 0, 1, 2, 3, 4 through the pointer:\n"); 
    for (int i = 0; i < arraySize; i++)
    {
        p[i] = i;
        printf("x[%d]: %d, p[%d]: %d\n", i, x[i], i, p[i]);
    }
    
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
