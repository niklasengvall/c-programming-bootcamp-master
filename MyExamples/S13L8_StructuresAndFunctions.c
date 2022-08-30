#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

// Aliasing the type with typedef (good practice)
typedef struct Guy // <-- structures name
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // in general you cannot use incomplete array, but... see Flexible Array Member
    struct Guy *friend;         // <-- pointer to another structure of same type
} Guy;                          // <-- alias name to structures name

// Function that returns a structure
Guy createBill()
{
/*    Guy bill = {
        .name = "Niklas Engvall",
        .pos = {1, 2, 3},
        .dimensions = 3,
        .active = true,
    };
    return bill; // return a copy of the structure */
    return (Guy) { // You can return a struct without reserving a variable for it
        .name = "Niklas Engvall",
        .pos = {1, 2, 3},
        .dimensions = 3,
        .active = true,
    };
}

// Function that returns a pointer to a structure, preferable as its saves a lot of memory
Guy *allocElon()
{
    Guy *elon = malloc(sizeof(Guy));
    
    if (!elon)
    {
        return NULL; // If system fails to allocate memory
    }
    
    // Settings...
    elon->name = "Elon Musk";
    elon->active = true;
    elon->dimensions = 3;
    // Alternative way to insert values form an array to a struct pointer with memcpy (string.h)
    double pos[] = {4, 5, 6}; // pos will be the arrays starting address
    memcpy(elon->pos, pos, sizeof(pos));
    elon->friend = NULL; // Important to initiate all members due to posible future malfunctions
 
    return elon; // Returns address to the allocated memory
}

void deactivateGuy(Guy g)
{
    g.active = false; // Change amember of a copied Guy struct, NO good
}

void deactivateGuyPtr(Guy *gp)
{
    gp->active = false;
}

int main()
{
    printf("\n=== Structures And Functions ===\n\n");

    Guy bill = createBill(); // Memory consuming way
    bill.friend = allocElon(); // Attaching elons structure pointer address to bills single linked struct list

    deactivateGuy(bill); // Does not work 

    deactivateGuyPtr(&bill); // Works

    free(bill.friend);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
