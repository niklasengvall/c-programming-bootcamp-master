#include <stdio.h>
#include <stdlib.h>

/***
 * === Sphere ===
 * Calculate surface and volume of a sphere
 *
 * Goals:
 *   - prompt user to enter the radius
 *   - calculate the surface area
 *   - calculate the enclosed volume
 *   - print the radius and the results in decimal format (2 digits of precision)
 *   - print the radius and the results in scientific notation (3 digits of precision)
 *   - check the results
 */

int main(void)
{
    const double PI = 3.14159265358979L; // PI with 15 digits
    double radius, surfaceArea, volume;

    printf("\n=== Sphere ===\n\n");
    printf("Enter radius of the sphere: ");
    scanf("%lf", &radius);

    surfaceArea = 4 * PI * radius * radius;
    volume = (4.0 / 3) * PI * radius * radius * radius;

    printf("Decimal:\n"); 
    printf("radius:  %.2f\n", radius);
    printf("surface: %.2f\n", surfaceArea);
    printf("volume:  %.2f\n", volume);

    printf("\nScientific:\n");
    printf("radius:  %.3E\n", radius);
    printf("surface: %.3E\n", surfaceArea);
    printf("volume:  %.3E\n", volume);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}