#include <stdio.h>
#include <stdlib.h>

int main()
{
    int apples = 12;
    int bananas = 9;
    int fruits = apples + bananas;

    printf("In the fruitbowl, there are:\n");
    printf("\t%d apples\n", apples);
    printf("\t%d bananas\n", bananas);
    printf("giving a total of %d fruits.\n", fruits);

    return EXIT_SUCCESS;
}
