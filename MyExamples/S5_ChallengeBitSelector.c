#include <stdio.h>
#include <stdlib.h>

/***
 * === Bit Selector ===
 * 
 * data: 0xABCD (hex)
 * 
 * Goals:
 *  - N, M design variables
 *  - make a selector that selects the bits [N:M] included
 *  - print data and result in hexadecimal format, 4 digits wide, zero padding
 *  - check these selection ranges:
 *    -   [0:3] expected result 0x000D
 *    -   [4:7] expected result 0x000C
 *    -  [8:11] expected result 0x000B
 *    - [12:15] expected result 0x000A
 * 
 */

int main(void)
{
    unsigned short data = 0xABCD; // Example data
    unsigned short N;             // bitmask start position
    unsigned short M;             // bitmask end position
    unsigned short W;             // bitmask width in number of bits
    unsigned short bitmask;       // What bits we don't want to clear/reset to 0
    unsigned short result;        // The bit range we want to print out
    
    printf("\n=== Bit Selector ===\n\n");
    // My short way solution

    printf("My solution:\n"); 
    printf("data: 0x%04hX, size in bytes: %ld\n", data, sizeof(data)); // Not neccesary but I wanted to use short with 16 bits variable
    printf("data: 0x%04hX, selection [0:3]:   0x%04hX\n", data, data & 0x000F); 
    printf("data: 0x%04hX, selection [4:7]:   0x%04hX\n", data, (data >> 4) & 0x000F); 
    printf("data: 0x%04hX, selection [8:11]:  0x%04hX\n", data, (data >> 8) & 0x000F); 
    printf("data: 0x%04hX, selection [12:15]: 0x%04hX\n", data, (data >> 12) & 0x000F); 
    
    // Code Garages solution
    printf("\n Code Garages solution:\n"); 
    N = 0;
    M = 3;
    W = M - N + 1;                  // to count in the zero digit we have to add 1. (3 - 0 + 1 =  4 bits in this calculation)
    bitmask = (1 << W) - 1;         // shift 1 to the left by W steps minus 1. ( in this calculation 0b00001 -> 0b10000 and - 1 => 0b01111 or 0xF
    result = (data >> N) & bitmask; // shift data N bits to the right and make a bitwise AND operation with the bitmask
                                    // In this example, shift data 0 positions to the right, so 0xABCD AND 0x000F will give the result = 0x000D

    printf("data ----> 0x%04hX\n", data); 
    printf("result --> 0x%04hX\n", result); 

    N = 4;
    M = 7;
    W = M - N + 1;                  // 7 - 4 + 1 =  4 bits in this calculation)
    bitmask = (1 << W) - 1;         // shift 0b00001 -> 0b10000 and - 1 => 0b01111 or 0xF
    result = (data >> N) & bitmask; // shift data 4 positions to the right, so 0xABCD -> 0x0ABC AND 0x000F will give the result = 0x000C
                                    
    printf("data ----> 0x%04hX\n", data); 
    printf("result --> 0x%04hX\n", result); 

    N = 8;
    M = 11;
    W = M - N + 1;                  // 11 - 8 + 1 =  4 bits in this calculation)
    bitmask = (1 << W) - 1;         // shift bitmask 0b00001 -> 0b10000 and - 1 => 0b01111 or 0xF
    result = (data >> N) & bitmask; // shift data 8 bits to the right, so 0xABCD -> 0x00AB AND 0x000F will give the result = 0x000B
                                    
    printf("data ----> 0x%04hX\n", data); 
    printf("result --> 0x%04hX\n", result); 

    N = 12;
    M = 15;
    W = M - N + 1;                  // 15 - 12 + 1 =  4 bits in this calculation)
    bitmask = (1 << W) - 1;         // shift bitmask 0b00001 -> 0b10000 and - 1 => 0b01111 or 0xF
    result = (data >> N) & bitmask; // shift data 12 bits to the right, so 0xABCD -> 0x000A AND 0x000F will give the result = 0x000A
    
    printf("data ----> 0x%04hX\n", data); 
    printf("result --> 0x%04hX\n", result); 

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}