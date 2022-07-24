#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

int main()
{
    printf("\n=== Pointers ===\n"); 

    char a = 'A';
    char *ptr = &a;

    // Prints the memoryaddress as 16 char wide hex value, filled with zeroes
    // printf("1 | %c, %c, 0x%016lX\n", a, *ptr, (uint64_t) ptr); 

    // Prints the memoryaddress as a long int and use char
    printf(" 1 | %c, %c, %lu\n", a, *ptr, (uint64_t) ptr); 

    char b = 'B';
    ptr = &b;
    printf(" 2 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr); 

    *ptr = 'C'; // Change value and reassign b to the nev char C
    printf(" 3 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr); 

    (*ptr)++; // Compound operation - and increment its value by 1 
    printf(" 4 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr); 

    // Use integers now 
    unsigned x = 'A';
    ptr = (char *) &x;
    printf(" 5 | %u, %c, %lu\n", x, *ptr, (uint64_t) &x); 

    unsigned y = 'B';
    ptr = (char *) &y;
    printf(" 6 | %u, %c, %lu\n", y, *ptr, (uint64_t) &y); 

    *ptr = 'C'; // Change value and reassign b to the nev char C
    printf(" 7 | %u, %c, %lu\n", y, *ptr, (uint64_t) &y); 

    (*ptr)++; // Compound operation - and increment its value by 1 
    printf(" 8 | %u, %c, %lu\n", y, *ptr, (uint64_t) &y); 

    x = 0xABCD1234;
    ptr = (char *) &x;
    printf(" 9 | %X, %X, %c\n", x, *ptr, *ptr); 

    *ptr = 'C';
    printf("10 | %u, %X, %X, %c\n", x, x, *ptr, *ptr); 

    // Assign 'C' to the whole unsigned int pointer 
    unsigned *uint_ptr = (unsigned *) ptr;
    *uint_ptr = 'C';
    printf("11 | %u, %X, %X, %c\n", x, x, *uint_ptr, *uint_ptr); 

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

