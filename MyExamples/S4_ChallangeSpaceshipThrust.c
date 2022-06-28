#include <stdio.h>
#include <stdlib.h>

/**
 * === Spaceship Thrust ===
 *
 * We are working on the man-machine interface of a revolutionary spaceship.
 * Define enumeration constants for different predefined thrust levels, these
 * levels will be used to communicate with the engine controller.
 *
 * The thrust levels are:
 *  - none:     0
 *  - low:      5
 *  - medium:   9
 *  - high:     12
 *  - maximum:  20
 *
 * Then launch the rocket!
 * We now want to print the thrust level in some critical points:
 *  - set thrust to none ---> print ready to go level
 *  - set thrust to maximum ---> print take off level
 *  - set thrust to medium ---> print entry into the ionosphere
 *  - set thrust to low ---> print traveling to deep space
 *
 */
typedef enum
{
    NONE,
    LOW = 5,
    MEDIUM = 9,
    HIGH = 12,
    MAXIMUM = 20
} RocketThrust;

int main(void)
{
    printf("=== Spaceship Thrust ===\n\n");

    RocketThrust thrust;

    thrust = NONE;
    printf("Thrust level: %d - Ready to go!\n", thrust);

    thrust = MAXIMUM;
    printf("Thrust level: %d - Take Off!\n", thrust);

    thrust = MEDIUM;
    printf("Thrust level: %d - Entry into the ionosphere!\n", thrust);

    thrust = LOW;
    printf("Thrust level: %d - Traveling to deep space!\n", thrust);
    printf("\nHave a nice journey into the unknown!\n");

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}