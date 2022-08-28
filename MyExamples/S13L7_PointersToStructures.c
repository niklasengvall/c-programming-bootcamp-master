#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main()
{
    printf("\n=== Pointers To Structures ===\n\n");

    // Explicit initialization, preferable method, it's more clear to the coder
    Guy bill = {
        .name = "Bill Gates",
        .pos = {3, 2, 1}, // array data, we dont need to put them in top-down order
        .dimensions = 3,
        .active = true, // no need for comma in the last struct member, but it can be there, it doesn't matter but is preferable if we want to add something later on
    };

    Guy *firstGuy = &bill; // Pointer to a struct

    // 1) Accessing the struct directly
    printf("Guy's name: %s\n", bill.name);

    // 2) Accessing the struct through pointers using the indirection operator
    printf("Guy's name: %s\n", (*firstGuy).name);

    // 3) Accessing the struct through pointers using the arrow operator
    printf("Guy's name: %s\n", firstGuy->name);
    printf("Guy's position: %.1f, %.1f, %.1f\n",
           firstGuy->pos[0],
           firstGuy->pos[1],
           firstGuy->pos[2]);

    // Walking a single linked list...
    firstGuy->friend = malloc(sizeof(Guy));
    firstGuy->friend->name = "Elon Musk";
    firstGuy->friend->active = false;

    // Go through the list... manually!?!
    firstGuy->friend->friend = malloc(sizeof(Guy));
    firstGuy->friend->friend->name = "Niklas Engvall";

    // Allocating an array of guys
    int num = 10;
    Guy *manyGuys = malloc(num * sizeof(Guy));

    manyGuys[0].name = "Mario"; // Accessing though . operator dot notation
    manyGuys[0].friend = &bill;

    // Accessing the 2nd element of manyGuys using pointers
    (manyGuys + 1)->name = "Tom"; // Address to the next manyGuys element and it's name
    printf("manyGuys[1].name = %s\n", manyGuys[1].name);
    printf("(manyGuys + 1).name = %s\n", (manyGuys + 1)->name);

    // Return the allocated memory
    free(firstGuy->friend);
    free(firstGuy->friend->friend);
    free(manyGuys); 

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
