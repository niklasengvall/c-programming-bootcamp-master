#include <stdio.h>
#include <stdlib.h>

/**
 * === Minimum Power Of 2 ===
 * 
 * Goals:
 *  - Acquire user input as int
 *  - If input is positive:
 *    > print the smallest power of 2 greater than or equal to the number
 *  - If input is negative:
 *    > do nothing
 *  - Repeat until user enter -1
 * 
 */

int main()
{
    int userInput, number;

    do {
        number = 1;
        printf("Enter a number (-1 to exit): ");
        scanf("%d", &userInput);
        if (userInput > 0)
        {
            while (userInput >= number) {
                number <<= 1;
            }
            printf("Smallest power of 2 greater than or equal to the number %d is %d.\n", userInput, number); 
        }
    } while (userInput != -1);

    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
