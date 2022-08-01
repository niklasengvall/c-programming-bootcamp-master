#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

/**
 * === Prime Numbers Improved === 
 *
 * Prime number: integer number greater than 1, only divisible by 1 and itself
 * 
 * Goals:
 *  - Find all prime numbers below a given upper limit given by the user
 *  - Check that 2 < upper limit <= 1 million
 *  - Store prime numbers in an array of 100k integers
 *  - Optimize the program by using stored primenumbers
 *  - Compare the executiuon time of the simple version with the optimized one
 *  - Implement printing of primes found separately from the alogrithm
 *  - Print up to 50 primenumbers found
 * 
 * Simple version
 *  - given an input number, n, check whether it is evenly divisible by ANY NUMBER
 *    between 2 and sqrt(n) (i.e. that the division leaves no remainder)
 * 
 * Optimized version
 *  - given an input number, n, check whether it is evenly divisible by ANY PRIME NUMBER
 *    between 2 and sqrt(n) (i.e. that the division leaves no remainder)
 * 
 */

#define max_array 100000

const int LOWER_LIMIT = 2, UPPER_LIMIT = 1000000;
const int simple = 0, optimized = 1;

int noOfPrimes = 0, noOfPrimes2 = 0;

int primeArray[max_array];
int primeArray2[max_array];

// Function declarations
void ErrorMessage();
bool LimitCheck(int limit);
void PrimeCheck(int lowLimit, int maxLimit, int type);
bool IsPrime(int number, int type);
void printPrimes(const int elements, int array[elements]);

int main()
{
    printf("\n=== Prime Numbers ===\n\n");

    for (int i = 0; i < max_array; i++)
    {
        primeArray[i] = 0; 
        primeArray2[i] = 0; 
    }

    /* Find all prime numbers below upperLimit */
    int upperLimit;
    
    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);
    if (LimitCheck(upperLimit))
    {
        ErrorMessage();
        return EXIT_FAILURE;
    }

    //double n = sqrt(upperLimit);
    //printf("\nsqrt(%d) = %d\n", upperLimit, (int) n); 

    // Check for primes between 2 and upperLimit
    printf("Prime numbers up to %d:\n", upperLimit);

    // To store the execution time of a C program
    double time_spent = 0.0;
    clock_t begin = clock();    

    PrimeCheck(LOWER_LIMIT, upperLimit, simple);
    
    // Stop the clock
    clock_t end = clock(); 

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds.\n", time_spent);
    printf("\nAnd when I checked %d numbers, I found %d primes.\n\n", upperLimit - 2, noOfPrimes);
    
    printPrimes(noOfPrimes, primeArray);

    // Next time check
    double time_spent2 = 0.0;
    clock_t begin2 = clock();    

    PrimeCheck(LOWER_LIMIT, upperLimit, optimized);

    // Stop the clock
    clock_t end2 = clock(); 

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;

    
    printf("\nThe elapsed time is %f seconds.\n", time_spent2);
    printf("\nAnd when I checked %d numbers, I found %d primes.\n\n", upperLimit - 2, noOfPrimes2);

    printPrimes(noOfPrimes2, primeArray2);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

bool LimitCheck(int limit)
{
    return (limit < LOWER_LIMIT || limit > UPPER_LIMIT);
}

void ErrorMessage()
{
    printf("Error: must be %d < limit < %d\n", LOWER_LIMIT, UPPER_LIMIT);
}

void PrimeCheck(int lowLimit, int maxLimit, int type)
{
    if (type == simple)
    {
        for (int number = lowLimit; number < maxLimit; number++)
        {
            int ip = IsPrime(number, type);
            if (ip)
            {
                primeArray[noOfPrimes] = number;
                ++noOfPrimes;
            }
        }
    }
    if (type == optimized)
    {
        for (int number = lowLimit; number <= primeArray[noOfPrimes - 1]; number++)
        {
            int ip = IsPrime(number, type);
            if (ip)
            {
                primeArray2[noOfPrimes2] = number;
                ++noOfPrimes2;
            }
        }

    }
}
bool IsPrime(int number, int type)
{
    if (type == simple)
    {
        int n = sqrt(number);
        for (int i = LOWER_LIMIT; i <= n; i++)
        {   
            if (!(number % i))
            {
                return false;        
            }
        }
        return true;
    }
    if (type == optimized)
    {
        int n = sqrt(number);
        for (int i = LOWER_LIMIT; i <= n; i++)
        {   
            if (!(number % primeArray[i - LOWER_LIMIT]))
            {
                return false;        
            }
        }
        return true;
    }
}

void printPrimes(const int elements, int array[elements])
{
    for (int i = 0; i < 50; i++)
    {
        printf("%4d ", array[i]); 
    }
    printf("Last number: %d\n", array[elements-1]); 
    printf("\n"); 
}
