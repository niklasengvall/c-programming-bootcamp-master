#include <stdio.h>
#include <stdlib.h>

/**
 * === Float Decomposition ===
 * 
 * Build a program that decomposes integer and fractional parts of a floating point number.
 * 
 * Goals:
 *  - Write a function called decompose that recieves a floating point number
 *    and returns an integer part (int) and fractional part (float).
 *  - Acquire a floating point from the keyboard.
 *  - Use the decompose function and print to screen integer and fractional part.
 *  - Reconstruct the original floatingpoint number and print it
 * 
 *  Tips:
 *  - You might need pointers ;)
 *  - Think carefully about the const keyword
 */

void decompose(float float_number, int *const int_number, float *const float_fraction)
{
    *int_number = (int) float_number;
    *float_fraction = float_number - *int_number; // No typeconversion to float needed on the int_number, great
}

int main()
{
    float fltInput, fltFraction;
    int intNumber;

    printf("\n=== Float Decomposition ===\n\n"); 

    // Acquire a float from user
    printf("Enter a floating point number: ");
    scanf("%f", &fltInput);

    // Decompose it into a integer and fractional part
    decompose(fltInput, &intNumber, &fltFraction);
    printf("Integer part of %.2f: %d\n", fltInput, intNumber);
    printf("Fractional part of %.2f: %.2f\n", fltInput, fltFraction); 

    // Reconstruct the original floating point number
    float reconstructed = intNumber + fltFraction; // No need to typeconvert here either
    printf("Reconstructed number: %.2f\n", reconstructed); 
    
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
