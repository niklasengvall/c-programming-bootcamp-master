#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DIMENSIONS 3

// Struct declaration
struct GuyStruct                      // Name of the struct
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // in general you cannot use incomplete array, but... see Flexible Array Member
};

// Aliasing the type with typedef (anonymous struct) avoid if possible
typedef struct // <-- structure has no name
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // in general you cannot use incomplete array, but... see Flexible Array Member
} GuyAnonymous;

// Aliasing the type with typedef (good practice)
typedef struct Guy // <-- structures name
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // in general you cannot use incomplete array, but... see Flexible Array Member
    struct Guy *friend; // <-- pointer to another structure of same type
} Guy; // <-- alias name to structures name

// Nested structures
typedef struct Motorcycle
{
    char *model;
    double speed;
    Guy owner;
} Motorcycle;

double calc_distance(int dimensions, double a[dimensions], double b[dimensions]) // variable length arrays
{
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++)
    {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
    
}
int main()
{
    printf("\n=== Defining And Accessing Structures ===\n\n");

    // Let's calculate the distance between two guys

    Guy elon, bill;
    Motorcycle mc;

    mc.model = "honda";
    mc.speed = 300;
    mc.owner.name = "Niklas";
    mc.owner.active = false;
    mc.owner.dimensions = 3;
    mc.owner.pos[0] = 4;
    mc.owner.pos[1] = 5;
    mc.owner.pos[2] = 6;

    // This example is structured
    elon.name = "Elon Musk";
    elon.active = false;
    elon.dimensions = 3;
    elon.pos[0] = 1;
    elon.pos[1] = 2;
    elon.pos[2] = 3;

    bill.name = "Bill Gates";
    bill.active = true;
    bill.dimensions = 3;
    bill.pos[0] = 3;
    bill.pos[1] = 2;
    bill.pos[2] = 1;

    if (!elon.active || !bill.active) // If one of em isn't active, print out which one and exit program
    {
        printf("%s isn't active!\n", !elon.active ? elon.name : bill.name);
        return EXIT_FAILURE;
    }
    
    if (elon.dimensions != bill.dimensions)
    {
        printf("%s and %s are in different dimensions!\n", elon.name, bill.name);
        return EXIT_FAILURE;
    }
    
    printf("The distance between %s and %s is: %.1f\n", 
            elon.name, bill.name, calc_distance(elon.dimensions, elon.pos, bill.pos));

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
