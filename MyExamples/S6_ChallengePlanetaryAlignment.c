#include <stdio.h>
#include <stdlib.h>

/**
 * === Planetary Alignment with for loops and breaks ===
 * 
 * Context:
 *  - three planets orbits around a star (a, b ,c)
 *  - each orbit takes x units of time
 *  - unit of time: one day (86 400 seconds)
 * 
 * Goals:
 *  - calculate how many days elapse between planets linear alignment
 *  - calculate how many orbits each planet makes arount the star in this time
 * 
 * Tips:
 *  - orbits duration: a, b, c (days) --> linear alignment lcm(a, b, c) days
 *    lcm stands for least common multiple that planet a, b and c share 
 *  - each planet completes lcm(a, b, c) / x orbits around the star
 * 
 * Trace:
 *  - get the duration (in days) of orbits a, b, c from the user
 *  - calculate lcm(a, b, c):
 *    > store the maximum between a, b, c
 *    > iterate no more than 10 000 times
 *    > check lcm(a, b, c) using the stored max and the modulo operator
 *    > if exceeded the maximum number of iterations: print a warning
 *    > else: print the result and the number of complete orbits for each planet
 * 
 * Test:
 *  - calculate Earth-Venus-Mercury linear alignment
 *  - calculate Earth-Mars-Jupiter linear alignment
 *  - check orbits duration here https://spaceplace.nasa.gov/years-on-other-planets/en/
 *
 *    Mercury:    88 days 
 *    Venus:     225 days 
 *    Earth:     365 days 
 *    Mars:      687 days 
 *    Jupiter: 4 333 days  
 */


int main()
{
    char  planet = 'a';
    const int    NO_OF_PLANETS   =       3;
    const int    MAX_ITERATIONS  = 1000000;
    const long   SECONDS_PER_DAY =   86400;
    long         lcm = -1;
    long         planetsOrbitTime[3]; // An array which stores orbit time in no of days for 3 planets 
    long         maxOrbitTime = 0;
    
    printf("\n=== Planetary Alignment with for loops and breaks ===\n\n");

    printf("%ld\n", sizeof(long));
    // Get the orbit duration in days from the user
    printf("Enter 3 planets orbit time around the sun:\n");
    for (int c = 0; c < NO_OF_PLANETS; c++)
    {
        printf("Enter planet %c orbit time around the sun: ", planet + c);
        scanf("%ld", &planetsOrbitTime[c]);
        // Recalculate it to seconds
        planetsOrbitTime[c] *= SECONDS_PER_DAY;
    } 
    
    // Print all we input to the console
    for (int c = 0; c < NO_OF_PLANETS; c++)
    {
        printf("\nPlanet %c -> %5ld [days]", planet + c, planetsOrbitTime[c] / SECONDS_PER_DAY);
    } 
    printf("\n"); 

    // Find out the maximum orbit time 
    for(int c = 0; c < NO_OF_PLANETS; c++)
    {
        if (planetsOrbitTime[c] > maxOrbitTime) 
        {
            maxOrbitTime = planetsOrbitTime[c];
        }
    }
    
    // Look for the least common multiple where all planets are aligned
    for (int i = 1; i < MAX_ITERATIONS; i++)
    {
        long mul = maxOrbitTime * i;
        if (mul % planetsOrbitTime[0] == 0 && mul % planetsOrbitTime[1] == 0 && mul % planetsOrbitTime[2] == 0)
        {
            lcm = mul;
            printf("\nIterations: %d\n\n", i);
            break;
        }
    }

    // Check if we exceeded MAX_ITERATIONS
    if (lcm == -1)
    {
        printf("WARNING: Exceeded number of max %d iterations.\n", MAX_ITERATIONS); 
    }
    else 
    {
        printf("Orbits a, b, c align every %ld days.\n", lcm / SECONDS_PER_DAY); 
        printf("Planet a completes %ld orbits.\n", lcm / planetsOrbitTime[0]); 
        printf("Planet b completes %ld orbits.\n", lcm / planetsOrbitTime[1]); 
        printf("Planet c completes %ld orbits.\n", lcm / planetsOrbitTime[2]); 
    }
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
