#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * === Prime Numbers ===
 * 
 * Definition:
 *    A prime number is an integer number greater than 1, only divisible by 1 and itself
 * Goals:
 *  - Find all prime numbers below a given upper limit
 *  - Find the first prime number above a given lower limit 
 *  - Write some dummy cleanup code before the final return (simply print something)
 *  - Define constant MAX equal to 1000
 *  - If user give an upper limit lower than 2 or greater than MAX immediately 
 *    execute the cleanup code and exit the program
 *  - Same check for the lower limit 
 * 
 * Tips:
 *  - How to check if x is a prime number:
 *    > scan all numbers from 2 to x
 *    > use the modulo operator to find out if x is prime
 */
int main()
{
    const unsigned int MIN_INTERVAL = 2;
    const unsigned int MAX_INTERVAL = 1000;

    unsigned int x;          // where we store the number to test if it's a prime number
    unsigned int lowerLimit;
    unsigned int upperLimit;
    unsigned int firstPrimeNumber = -1;
    bool         foundFirstPrimeNumber = false;
    bool         test;
    bool         isPrime = true;

    printf("\n=== Prime Numbers ===\n\n"); 
     
    printf("Enter lowest number to start check for primes: ");
    scanf("%u", &lowerLimit);
    printf("Enter highest number to end check for primes:  ");
    scanf("%u", &upperLimit);

    // Test if user have entered a valid number between MIN_INTERVAL and MAX_INTERVAL
    // Also the lowest number must be lesser or equal to the highest number
    // If not, inform the user and exit the program 
    if (upperLimit < MIN_INTERVAL || upperLimit > MAX_INTERVAL || lowerLimit < MIN_INTERVAL || lowerLimit > MAX_INTERVAL || lowerLimit > upperLimit)
    {
        printf("ERROR: Lowest and highest number must be between %u and %u. Also lowest number must be same or lesser than highest number.\n", MIN_INTERVAL, MAX_INTERVAL);
        goto end_of_code;
    }

    printf("Prime numbers up to %d:\n", upperLimit); 
    for (x = lowerLimit; x <= upperLimit; x++) // Test every number 
    {
        for (unsigned int d = 2; d < x; d++) // We dont test to divide x by itself (d < x)
        {
            isPrime = true; // Default to say x is a prime number
            test = x % d ? false : true; // test should be false with all numbers in this loop - then it's a prime number
            if (test) // If its dividable without a reminder it's not a prime number
            { 
                isPrime = false;
                break; // breakout of this loop, we found a number thats divisible by other numbers than itself
            }
        }
        if (isPrime) // If it's a prime number print it on the screen
        {
            if(!foundFirstPrimeNumber)
            {
               foundFirstPrimeNumber = true;
               firstPrimeNumber = x;
               printf("The first prime number above %d is %d\n",lowerLimit, firstPrimeNumber);  
            }
            printf("%d ", x);
        }
    }
    if (!foundFirstPrimeNumber)
    {
        printf("Cannot find prime numbers between %d and %d\n",lowerLimit, upperLimit); 
    }

    printf("\n"); 
end_of_code:    
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
