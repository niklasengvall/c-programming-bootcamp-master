#include <stdio.h>
#include <stdlib.h>

#define LEN 5 // Defines a macro that replaces all LEN with 5. We can't use variable or constants with brace-initialization

int main()
{
    printf("\n=== Initializing Arrays ===\n"); 
   
    // Declarations
    int a[LEN]; //a has type int[5] its declared only and contains unpredictable values!

    // Before moving on we need variable a to contain all ones "1", an old method to initialize an array
    for (int i = 0; i < LEN; i++)
    {
        a[i] = 1;
    }
    
    // Array initialization from brace-enclosed lists
    int x[] = {1, 2, 3, 4, 5}; // Compiler defines arrays size, x has type int[5] and holds 1, 2, 3, 4, 5
    int y[LEN] = {1, 2, 3}; // Illegal with variable and constants, y has type int[5] and holds 1, 2, 3, 0, 0
    int z[LEN] = {0}; //z has type int[5] and holds 0, 0, 0, 0, 0

    // Array initialization with designators (sparse array)
    int w[LEN] = {[1] = 1, [3]= 1};        // w has type int[5] and holds 0, 1, 0, 1, 0
    int q[LEN] = {[1] = 3, [LEN - 1] = 5}; // q has type int[5] and holds 0, 3, 0, 0, 5
    int t[10] = {[0] = 5, 4, [LEN - 3] = 3, 2, 1}; // t has type int[10] and holds 5, 4, 0, 0, 0, 0, 0, 3, 2, 1

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
