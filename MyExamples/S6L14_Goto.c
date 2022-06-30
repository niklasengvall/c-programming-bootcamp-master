#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input, accumulator = 0;
    const int ITERATIONS = 5;
    int returnValue;

    printf("\n=== Test of Goto ===\n\n"); 
    printf("Enter 5 positive integers\n\n"); 

    // Ask for 5 numbers
    for (int i = 0; i < ITERATIONS; i++)
    {
        printf("Enter integer %d (> 0): ", i + 1);
        returnValue = scanf("%d", &input);

        // Checks if we input something else than positive integer numbers 
        if (!returnValue || input <= 0) 
        { 
            printf("\nERROR: You should only input positive integers!\n"); 
            goto end_of_code;
        }
        accumulator += input > 0 ? input : 0;
    }
    
    printf("\nAccumulator: %d\n", accumulator);     
end_of_code:    
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
