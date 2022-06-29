#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * === Even Odd ===
 * 
 * Goals:
 *  - prompt user to enter a positive integer number
 *  - if number is negative print a warning and exit
 *  - check if number is even or odd and store the result
 *    in a boolean variable using the ternary operator
 *  - print whether the number is even or odd
 * 
 */

int main()
{
    int posIntNum;
    bool result;

    printf("\n=== Even Odd ===\n\n"); 
    printf("Enter a positive integer number: ");
    scanf("%d", &posIntNum);
    // Check if user inputs a negative value
    if (posIntNum < 0)
    {
        printf("WARNING: %d is a negative number. You should enter a positive integer value!\n", posIntNum); 
        return EXIT_FAILURE;
    }
    result = posIntNum % 2 ? false : true;
    if (result)
    {
        printf("Your number %d is even.\n", posIntNum); 
    }
    else
    {
        printf("Your number %d is odd.\n", posIntNum); 
    }
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
