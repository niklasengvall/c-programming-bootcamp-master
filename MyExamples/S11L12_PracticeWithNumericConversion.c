#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>


int main()
{
    printf("\n=== Practice With Numeric Conversion ===\n\n"); 

    char str[] = "-123 10000000000000000000000000 99 -7";
    char *pend, *pstart = str;

    while(true)
    {
        long num = strtol(pstart, &pend, 10);

        printf("\nConverting: %s \n", pstart); 
        printf("errno: %d %s\n", errno, errno == ERANGE ? "(ERANGE)" : ""); 
        printf("%s\n", pend == pstart ? "pend == pstart (ERROR)" : "pend != pstart (OK)"); 

        if (errno || pend == pstart)
        {
            printf("Conversion error!\n");
            errno = 0; 
        }
        else
        {
            printf("Conversion: %ld\n", num); 
        }

        if (pend == pstart)
        {
            break;
        }
        pstart = pend;     
    }
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
