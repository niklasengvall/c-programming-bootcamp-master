#include <stdio.h>
#include <stdlib.h>

enum menu {
    TEA,            // 0 as datatype int
    COFFE,          // 1 as datatype int
    JUICE = 100,    // 100 as datatype int
    BEER           // 101 as datatype int (as you see it continues from last enumration)
};

int main(void)
{

    enum menu mario = COFFE;
    enum menu andrea = BEER;

    printf("Mario ordered:  %d\n", mario);
    printf("Andrea ordered: %d\n", andrea);
    

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}