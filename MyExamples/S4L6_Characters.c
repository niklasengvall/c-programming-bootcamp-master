#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char c = 'A';

    printf("char c: %d\n", c); // prints the ascii code
    printf("char c: %c\n", c); // prints the character

    c = 66; // Assigning a new number to the c variable
    printf("char c: %c\n", c); // prints the character

    // Acquire user input 
    printf("Input a character: ");
    c = getchar();
    printf("You entered: %c\n", c); // prints the first character from the input buffer if you entered several before pressing ENTER
   
    c = getchar();
    printf("You entered: %c\n", c); // prints the second character


    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}