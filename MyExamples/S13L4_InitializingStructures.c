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

    // Implicit initialization
    Guy elon = {
        "Elon Musk", 
        true, 
        3, 
        {1, 2, 3} // array data
    };

    // Explicit initialization, preferable method, it's more clear to the coder
    Guy bill = {
        .name = "Bill Gates", 
        .pos = {3, 2, 1}, // array data, we dont need to put them in top-down order
        .dimensions = 3,
        .active = true, // no need for comma in the last struct member, but it can be there, it doesn't matter but is preferable if we want to add something later on
    };

    Motorcycle mc = {
        .model = "honda",
        .speed = 100,
        .owner = {
            .name = "Niklas",
            .active = true,
            .dimensions = 3,
            .pos = {4, 5, 6},
        },
    };

    // Copying a whole structure with = 
    Guy anotherGuy = {.name = "Someone", .active = false};
    anotherGuy = bill;

    printf("anotherGuy.name = %s\n", anotherGuy.name);
    
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

    printf("And %s motorcycle is running at %.1f km/h and is driven by %s\n", 
        mc.model, mc.speed, mc.owner.name);
    
    mc = (Motorcycle) {.model = "Ducati", .speed = 200, .owner.name ="Nisse"}; // Obs type casting, unset members is set to NULL
    
    printf("And %s motorcycle is running at %.1f km/h and is driven by %s\n", 
        mc.model, mc.speed, mc.owner.name);


    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
