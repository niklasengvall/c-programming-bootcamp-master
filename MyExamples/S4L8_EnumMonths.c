#include <stdio.h>
#include <stdlib.h>

enum months {
    JAN = 1,    // Set the no of month to 1 
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int main(void)
{

    enum months my_fav_month = JUL;
    enum months my_worst_month = NOV;


    printf("My favourite month:  %d\n", my_fav_month);
    printf("My worst month:      %d\n", my_worst_month);
    

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}