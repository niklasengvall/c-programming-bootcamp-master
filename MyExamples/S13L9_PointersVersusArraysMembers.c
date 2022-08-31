#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

typedef struct GuyP // Job member is a pointer
{
    char *name;                     // 8
    char *job;                      // 8
    bool active;                    // 1 (4 in reality)
    int dimensions;                 // 4
    double pos[MAX_DIMENSIONS];     // 24
} GuyP;

typedef struct GuyA // Job member is an Array
{
    char *name;
    char job[64];
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; 
} GuyA;

int main()
{
    printf("\n=== Pointers Versus Arrays Members ===\n\n");

    printf("Sizeof(GuyP): %3ld bytes\n", sizeof(GuyP));
    printf("Sizeof(GuyA): %3ld bytes\n", sizeof(GuyA));

    GuyP billP = {
        .name = "Bill Gates",
        .job = "I make software...",
        .active = true,
    };

    billP.job = "I founded Microsoft!"; // Let job point to a new string litteral stored elsewhere

    GuyA billA = {
        .name = "Bill Gates",
        .job = "I make software...",
        .active = true,
    };

    //billA.job = "I founded Microsoft!"; // wrong!
    strncpy(billA.job, "I founded Microsoft!", sizeof(billA.job) - 1); // Alwaays remember space for null char, 

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
