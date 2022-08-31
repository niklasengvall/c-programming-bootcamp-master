#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;                     
    bool active;                    
    int dimensions;                 
    double pos[MAX_DIMENSIONS];
} Guy;

typedef struct GuyFlex
{
    char *name;                     
    bool active;                    
    int dimensions;                 
    double pos[];       // only possible when the array is the last member of a struct
} GuyFlex;

typedef struct BleHeader 
{
    uint16_t    PDUType : 4;
    uint16_t    RFU1    : 2;
    uint16_t    TxAdd   : 1;
    uint16_t    RxAdd   : 1;
    uint16_t    Length  : 6;
    uint16_t    RFU2    : 2;
} BleHeader;

typedef struct BlePacket
{
    BleHeader header; // A nested struct
    uint8_t payLoad[];
} BlePacket;

GuyFlex *allocGuy(int dimensions)
{
    size_t size = sizeof(((GuyFlex *)0)->pos[0]);               // Flexible way to grab the correct size of pos member if we change type in the struct
    GuyFlex *guy = malloc(sizeof(GuyFlex) + dimensions * size);
    
    if (!guy)
    {
        return NULL;
    }
    guy->dimensions = dimensions;

    return guy;
}

void ReadBlePacket(BlePacket *packet)
{
    int len = packet->header.Length;
    for (int i = 0; i < len; i++)
    {
        printf("%X ", packet->payLoad[i]); // Print each value as HEX in payLoad
    }
    printf("\n");
}

int main()
{
    printf("\n=== Flexible Array Members ===\n\n");

    printf("sizeof(Guy): %ld\n", sizeof(Guy));
    printf("sizeof(GuyFlex): %ld\n", sizeof(GuyFlex));

    
    GuyFlex *niklas = allocGuy(3);
    niklas->name = "Niklas Engvall";
    niklas->active = true;
    double pos[] = {7, 8, 9}; // pos will be the arrays starting address
    memcpy(niklas->pos, pos, sizeof(pos));
 
    printf("Name: %s, dimensions: %d\n", niklas->name, niklas->dimensions);

    const uint8_t rxBuffer[] = {0x41, 0x06, 0xCa, 0xFE, 0xCA, 0xFE, 0xCA, 0xFE};
    ReadBlePacket((BlePacket *) rxBuffer);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
