#include <stdio.h>  
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int a = 1000000; // 1e6
    int b = 5000000; // 5e6

    //double c = a * b; // expected 5e12, number overflow cause they are calculated as ints before they are assigned to a double
    double c = (double) a * b; // We convert data type on a and imlicit also b
    printf("%.0e\n", c); 

    int si = -1; // signed int
    unsigned ui = 1; // unsigned int

    if (si < ui) // si is converted to UINT_MAX
    {
        printf("as expected\n"); 
    }
    else
    {
        printf("something is wrong\n"); 
    }

    if (si < (int) ui) // ui is converted to an int, rememberto compare same datatype as the leftmost operator
    {
        printf("as expected\n"); 
    }


    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
