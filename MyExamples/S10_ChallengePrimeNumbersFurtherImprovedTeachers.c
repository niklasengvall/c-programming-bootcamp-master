#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MIN_UPPER_LIMIT 3
#define MAX_UPPER_LIMIT 1000000
#define PRIME_FOUND_LEN 100000
#define PRINTABLE_LIMIT 50


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


bool isPrimeSimple(int num)
{
    const int limit = sqrt(num);
    for (int i = 2; i <= limit; i++)
    {
        if (num % i == 0)
        {
            // num is evenly divisible by i --> NOT a prime number
            return false;
        }
    }
    return true; // we found a prime number    
}

bool isPrimeOptimized(int num, int primeNumbers[], int found)
{
    const int limit = sqrt(num);
    for (int i = 0; i <= found && primeNumbers[i] <= limit; i++)
    {
        if (num % primeNumbers[i] == 0)
        {
            // num is evenly divisible by primeNumbers[i] --> NOT a prime number
            return false;
        }
    }
    return true; // we found a prime number 
}


bool isPrime(int num, bool optimized, int primeNumbers[], int found)
{
    return  optimized ? isPrimeOptimized(num, primeNumbers, found) : isPrimeSimple(num);
}

int getPrimeNumbers(int upperLimit, int primeNumbers[], bool optimized)
{
    int found = 0;

    for (int num = 2; num < upperLimit; num++)
    {
        if (isPrime(num, optimized, primeNumbers, found))
        {
            primeNumbers[found] = num;
            found++;
        }
    }
    return found;
}

void printNumbers(int numbers[], int len)
{
    printf("Found %d prime numbers.\n", len);
    for (int i = 0; i < len && i < PRINTABLE_LIMIT; i++)
    {
        printf("%d ", numbers[i]); 
    }
    printf("\n");    
}

double getElapsedTimeInSec(clock_t start, clock_t end)
{
    return (end - start) / (double) CLOCKS_PER_SEC;
}

int main()
{
    int upperLimit;

    printf("\n=== Prime Numbers Further Improved ===\n\n");

       
    printf("Enter an upper limit: (min %d, max %d) ", MIN_UPPER_LIMIT, MAX_UPPER_LIMIT);
    scanf("%d", &upperLimit);
    
    
    if (upperLimit < MIN_UPPER_LIMIT || upperLimit > MAX_UPPER_LIMIT)
    {
        printf("Out of bounds!\n");
        return EXIT_FAILURE;
    }

    int found, primeNumbers[PRIME_FOUND_LEN];

    // Check for primes between 2 and upperLimit
    printf("\nPrime numbers up to %d with simple method:\n", upperLimit);

    // To store the execution time of a C program
    clock_t begin, end;

    begin = clock(); // get the numbers of clock ticks elapsed since the program was launched      
    found = getPrimeNumbers(upperLimit, primeNumbers, false);
    end = clock(); 

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds

    printNumbers(primeNumbers, found);
    printf("\nThe elapsed time for simple version is %.1f ms.\n", getElapsedTimeInSec(begin, end) * 1e3);

    // Check for primes between 2 and upperLimit
    printf("\nPrime numbers up to %d with optimized method:\n", upperLimit);

    // Next time check with the optimized version
    begin = clock();    
    found = getPrimeNumbers(upperLimit, primeNumbers, true);
    end = clock(); 

    printNumbers(primeNumbers, found);
    printf("\nThe elapsed time for optimized version is %.1f ms.\n", getElapsedTimeInSec(begin, end) * 1e3);
   
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
