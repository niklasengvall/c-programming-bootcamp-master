#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct LedStatus
{
    uint8_t led_1;
    uint8_t led_2;
    uint8_t led_3;
} LedStatus;

typedef struct LedStatusBitfields
{
    uint8_t led_1 : 1; // Define the size to 1 bit
    uint8_t led_2 : 1;
    uint8_t led_3 : 1;
} LedStatusBitfields;

typedef struct BLEHeader {  // Example Bluethoth Low Energy Header
    uint16_t PDU_type : 4; 
    uint16_t RFU1     : 2; 
    uint16_t TxAdd    : 1; 
    uint16_t RxAdd    : 1; 
    uint16_t Length   : 6; 
    uint16_t RFU2     : 2; 
} BLEHeader;

// Print all bits from a selected pointer with size bytes
void printBits(uint8_t *data, int size)
{
    for (int i = size - 1; i >= 0; i--)             // Go from most significat byte to less significant byte 
    {
        uint8_t byte = data[i];                     // Take care of 1 byte at a time
        
        for (int j = 0; j < 8; j++)                 // Print all bits in order most to least significat bit 
        {
            printf("%d", (byte << j & 0x80) / 128); // Print value of bit 
        }
    }
    printf("\n");
}

int main()
{
    printf("\n=== Bit Fields ===\n\n");

    printf("sizeof(LedStatus): %ld\n", sizeof(LedStatus));
    printf("sizeof(LedStatusBitfields): %ld\n\n", sizeof(LedStatusBitfields));

    LedStatusBitfields status = {
        .led_1 = 1, // least significant bit
        .led_2 = 1,
        .led_3 = 1,
    };

    printBits((uint8_t *) &status, sizeof(status));

    status.led_1 = 0;
    status.led_2 = 0;

    printBits((uint8_t *) &status, sizeof(status));

    BLEHeader header = {
        .PDU_type = 3,
        .TxAdd = 1,
        .Length = 7,
    };
    
    printBits((uint8_t *) &header, sizeof(header));
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

