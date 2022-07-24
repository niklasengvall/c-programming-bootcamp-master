#include <stdio.h>
#include <stdlib.h>

// Testing for NULL pointer
int main()
{
    printf("\n=== NULL Pointers ===\n"); 

    int *ptr = NULL; // Points to a not valid memoryaddress equals to 0
    
    // Execute ONLY if ptr isn't NULL
    if (ptr) // (ptr != NULL) // Test if the adress that we are using isn't pointing to NULL
    {
        printf(" 1 | Pointed value: %d\n", *ptr); 
    }

    int someValue = 123;

    // Execute ONLY if ptr is NULL, we can say assign a value if we have a NULL pointer
    if (!ptr) // (ptr == NULL) // Test if the adress that we are using is pointing to NULL
    {
        ptr = &someValue;
    }

    // Execute ONLY if ptr isn't NULL
    if (ptr)
    {
        printf(" 2 | Pointed value: %d\n", *ptr); 
    }

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
