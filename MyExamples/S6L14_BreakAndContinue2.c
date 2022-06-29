#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input, accumulator = 0;
    const int ITERATIONS = 5;

    // Ask for 5 numbers
    for (int i = 0; i < ITERATIONS; i++)
    {
        printf("Enter an integer (> 0): ");
        scanf("%d", &input);

        if (input < 0) // if a negative numer is entered don't accumulate it
        {
            continue;
        }

        accumulator += input;
    }
    
    printf("\nAccumulator: %d\n", accumulator);     
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
