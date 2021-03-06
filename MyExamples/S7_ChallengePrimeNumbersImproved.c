#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * === Prime Numbers Improved === 
 *
 * Prime number: integer number greater than 1, only divisible by 1 and itself
 * 
 * Goals:
 *  - Find all prime numbers below a given upper limit
 *  - Find the first prime number above a given lower limit
 *  - Define constant MAX equal to 1000
 *  - If user give an upper limit lower than 2 or greater than MAX exit the program
 *  - Same check for the lower limit
 *  - Implement prime check, limit out of bounds check, and error print as functions
 * 
 * Tips:
 *  - How to check if x is a prime number:
 *    > scan all numbers from 2 to x
 *    > use the modulo operator to find out if x is prime
 * 
 */

const int MAX = 1000000;
int firstPrimeNumber = -1;
int noOfPrimes = 0;

int primeArray[100000];


// Function declarations
void ErrorMessage();
bool LimitCheck(int limit);
void PrimeCheck(int lowLimit, int maxLimit, int type);
bool IsPrime(int number);

int main()
{
    printf("\n=== Prime Numbers ===\n\n");

    /* Find all prime numbers below upperLimit */
    int upperLimit;
    const int primeBelow = 0;
    const int primeAbove = 1; 

    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);
    if (LimitCheck(upperLimit))
    {
        ErrorMessage();
        return EXIT_FAILURE;
    }

    // Check for primes between 2 and upperLimit
    printf("Prime numbers up to %d:\n", upperLimit);

    // To store the execution time of a C program
    double time_spent = 0.0;
    clock_t begin = clock();    

    PrimeCheck(2, upperLimit, primeBelow);
    
    // Stop the clock
    clock_t end = clock(); 

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds.\n", time_spent);
    printf("\nAnd when I checked %d numbers, I found %d primes.\n\n", upperLimit - 2, noOfPrimes);
    

    /* Find the first prime number above lowerLimit */
    int lowerLimit;
    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);
    if (LimitCheck(lowerLimit))
    {
        ErrorMessage();
        return EXIT_FAILURE;
    }
    
    PrimeCheck(lowerLimit, MAX, primeAbove);

    if (firstPrimeNumber == -1)
    {
        printf("Cannot find prime numbers above %d\n", lowerLimit);
    }
    else
    {
        printf("The first prime number above %d is %d\n", lowerLimit, firstPrimeNumber);
    }

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

bool LimitCheck(int limit)
{
    return (limit < 2 || limit > MAX);
}

void ErrorMessage()
{
    printf("Error: must be 2 < limit < MAX\n");
}

void PrimeCheck(int lowLimit, int maxLimit, int type)
{
    for (int number = lowLimit; number < maxLimit; number++)
    {
        int ip = IsPrime(number);
        if (ip && type == 0)
        {
            //printf("%d\n", number);
            primeArray[noOfPrimes] = number;
            ++noOfPrimes;
            
        }
        if (ip && type == 1)
        {
            firstPrimeNumber = number;
            break;
        }
    }   
}

bool IsPrime(int number)
{
    for (int i = 2; i < number; i++)
    {   
        if (!(number % i))
        {
            return false;        
        }
    }
    return true;
}   