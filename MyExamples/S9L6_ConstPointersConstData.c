#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Testing for NULL pointer
int main()
{
    printf("\n=== Const Pointers and Const Data ===\n"); 

    int birthDate = 711220;
    int anotherDate = 780629;
    int thirdDate = 160907;

    const int *ptr = &birthDate; // Make a constant int pointer, value could not be changed
    int *const ptr2 = &anotherDate; // Make a constant adress pointer, address could not be changed
    const int *const ptr3 = &thirdDate; // Make an absolute const pointer, neither address and int value can be changed.

    // Execute ONLY if ptr is NULL, we can say assign a value if we have a NULL pointer
    if (!ptr) // (ptr == NULL) // Test if the adress that we are using is pointing to NULL
    {
        ptr = &birthDate;
    }
    // Execute ONLY if ptr isn't NULL
    if (ptr)
    {
        printf(" 1 | birthDate: %d, %d, %lu\n", birthDate, *ptr, (uint64_t) ptr); 
        printf(" 2 | anotherDate: %d, %d, %lu\n", anotherDate, *ptr2, (uint64_t) ptr2); 
        printf(" 3 | thirdDate: %d, %d, %lu\n", thirdDate, *ptr3, (uint64_t) ptr3); 

        printf("Changing address for birthDate pointer to anotherDate pointers address:\n");
        ptr = ptr2;
        printf(" 4 | birthDate: %d, %d, %lu\n", birthDate, *ptr, (uint64_t) ptr); 

        printf("Changing value for anotherDate pointer to thirdDate pointers value:\n");
        *ptr2 = *ptr3;
        printf(" 5 | anotherDate: %d, %d, %lu\n", anotherDate, *ptr2, (uint64_t) ptr2); 

    }

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
