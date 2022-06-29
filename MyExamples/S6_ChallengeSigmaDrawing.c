#include <stdio.h>
#include <stdlib.h>

/**
 * === Sigma Drawing ===
 * 
 * Goals:
 *  - Print this drawing:
 * 
 *       xxxxxxxxxx
 *        x
 *         x
 *          x
 *           x
 *            x
 *           x
 *          x
 *         x
 *        x
 *       xxxxxxxxxx
 * 
 * Base width:   10
 * Tip width:     5
 * Total height: 11
 * 
 */

int main()
{
    const char symbol = 'x';
    
    const int baseWidth = 10;
    const int tipWidth = 5;
   
    printf("\n=== Sigma Drawing ===\n\n"); 
    // Start horizontal line
    for (int i = 0; i < baseWidth; i++) 
    {
        printf("%c", symbol); 
    }
    printf("\n");
    
    // Start diagonal line
    for (int i = 1; i < tipWidth; i++) // No of spaces start with 1
    {
        for (int j = 0; j < i; j++) 
        {
            printf(" ");   
        }
        printf("%c\n", symbol);
    }

    // End diagonal line
    for (int i = tipWidth; i > 0; i--) // No of spaces starts with 4
    {
        for (int j = 0; j < i; j++) 
        {
            printf(" ");   
        }
        printf("%c\n", symbol);
    }

    // End horizontal line
    for (int i = 0; i < baseWidth; i++) 
    {
        printf("%c", symbol); 
    }
    printf("\n");
 
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
