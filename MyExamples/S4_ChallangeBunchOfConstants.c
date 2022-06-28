#include <stdio.h>
#include <stdlib.h>

/**
 * === Bunch Of Constants ===
 *
 * Define the following numeric constants:
 *  - moonLanding: 1969
 *  - speedOfLight: 299792458
 *  - pi: 3.142
 *  - hexaDead: 0xDEAD
 *  - hexaSecret: 51966
 *
 * Print with following formats:
 *  - moonLanding:
 *      - integer, 10 characters width, padded with spaces
 *      - integer, 10 characters width, padded with zeroes
 *  - speedOfLight:
 *      - floating point without digits after decimal point
 *      - scientific notation with 3 digit of precision
 *  - pi:
 *      - floating point with 2 digits of precision
 *      - scientific notation with 1 digit of precision, sign forced
 *  - hexaDead:
 *      - unsigned hexadecimal integer, uppercase, leading 0x
 *      - unsigned integer, 6 characters width
 *  - hexaSecret:
 *      - unsigned hexadecimal integer, lowercase, no leading 0x
 *
 */

int main(void)
{
    const int moonLanding = 1969;
    const double speedOfLight = 299792458.0; // prefix L for storing all digits correctly
    const float pi = 3.142f;
    const unsigned int hexaDead = 0xDEADU;
    const unsigned int hexaSecret = 51966U;

    printf("=== Bunch Of Constants ===\n\n");

    printf("moonLanding: %10d\n", moonLanding); // right justified 10 steps with spaces
    printf("moonLanding: %010d\n", moonLanding); // filled with leading 0

    printf("speedOfLight: %.0f\n", speedOfLight); // 2 decimals
    printf("speedOfLight: %.3e\n", speedOfLight); // Scientific E notation with 3 decimals

    printf("pi: %.2f\n", pi); // 2 decimals float 
    printf("pi: %+.1e\n", pi); // leading sign and scientific notation with 1 decimal

    printf("hexaDead: %#X\n", hexaDead); // X prints leading 0x with # in capitalized style 
    printf("hexaDead: %6u\n", hexaDead); // right justified with 6 spaces

    printf("hexaSecret: %x\n", hexaSecret); // prints in hexadecimal styll in lowercase

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}