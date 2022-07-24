#include <stdio.h>
#include <stdlib.h>

/**
 * === Simple Swapper ===
 * 
 * Build a program that exchanges two integer values
 * 
 * Goals:
 *  - Implement the swap operation inside a function
 *  - The swap function must exchange the value of two int variables declared in main
 *
 *  Tips:
 *  - Use pointers
 *  - Think carefully about the const keyword
 */
/**
 * @brief swaps values between two integers
 * 
 * @param int *const ptr_a
 * @param int *const ptr_b
 */
void SwapInt(int *const ptr_a, int *const ptr_b)
{
    int tmp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = tmp;
}

int main()
{

    int a = 13, b = 27;

    printf("Before call to SwapInt: a = %d, b = %d\n", a, b); 

    int *pa = &a;
    int *pb = &b;
    
    SwapInt(pa, pb);

    printf("After call to SwapInt using pointers as parameters: a = %d, b = %d\n", a, b); 

    SwapInt(&a, &b);

    printf("After call to SwapInt using variable addresses as parameters: a = %d, b = %d\n", a, b); 

    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
