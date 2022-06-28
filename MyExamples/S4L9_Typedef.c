#include <stdio.h>
#include <stdlib.h>

typedef enum {  // instead of enum menu we make an alias Menu with typedef
    TEA,        // 0 as datatype int
    COFFE,      // 1 as datatype int
    JUICE,      // 2 as datatype int
    BEER        // 3 as datatype int (as you see it continues from last enumration)
} Menu;         // The new alias name Menu for this enum, use capital letter  

int main(void)
{
    Menu mario = COFFE; // Using my new alias Menu instead of enum menu;
    Menu andrea = BEER; // All typedefs should start with a capital letter

    printf("Mario ordered:  %d\n", mario);
    printf("Andrea ordered: %d\n", andrea);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}