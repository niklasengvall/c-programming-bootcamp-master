#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // 1.23456789
    double dbl_decimal_digits = 1.23456789;

    // 7.801 x 10^9 = Worlds population with scientific notation
    double dbl_world_population = 7.801E9;

    // 6.626 x 10^-34 - Planks constant
    double dbl_plank_constant = 6.626E-34;

    printf("%12.1f | 1 decimal digit\n", dbl_decimal_digits);
    printf("%12.3f | 3 decimal digit\n", dbl_decimal_digits);

    printf("%12.1f | dbl_world_population, decimal, 1 digit of precision\n", dbl_world_population);
    printf("%12.1e | dbl_world_population, scientific, 1 digit of precision\n", dbl_world_population);
    printf("%12.3e | dbl_world_population, scientific, 3 digit of precision\n", dbl_world_population);

    printf("%12.1E | dbl_plank_constant, scientific, 1 digit of precision\n", dbl_plank_constant);
    printf("%12.3E | dbl_plank_constant, scientific, 3 digit of precision\n", dbl_plank_constant);

    printf("\n\n=== ByteGarage ===\n\n");

    return EXIT_SUCCESS;
}