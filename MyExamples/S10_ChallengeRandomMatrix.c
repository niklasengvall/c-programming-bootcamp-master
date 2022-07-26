#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * === Random Matrix ===
 * 
 * Generate a random matrix and display it in direct and transposed form
 * 
 * Goals:
 *  - Generate ranom matrix with numbers of rows and columns given by the user
 *  - Check that 1 < rows <= 10, the same for the columns
 *  - Generate random matrix with 0 <= numbers < upper limit given by the user
 *  - Check that 1 < upper limmit <= 1000
 *  - Display the matrix in direct and transposed form
 * 
 * Tips:
 *  - To generate random numbers below an upper bound you may find the modulo operator useful... 
 */

const int MIN_ROWS = 2, MAX_ROWS = 10,
          MIN_COLS = 2, MAX_COLS = 10,
          MIN_UPPER_LIMIT = 2, MAX_UPPER_LIMIT = 1000;

void create_matrix(const int rows, const int cols, const int upper_limit, int matrix[rows][cols])
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            matrix[r][c] = rand() % upper_limit;    // create a random number 0 < MAX_UPPER_LIMIT           
        }
    }
}

void display_matrix(const int rows, const int cols, int matrix[rows][cols], bool transposed)
{
    for (int i = 0; i < (transposed ? cols : rows); i++)
    {
        for (int j = 0; j < (transposed ? rows : cols); j++)
        {
            printf("%4d ", matrix[transposed ? j: i][transposed ? i : j]); // Obs check how we can use ?: operator
        }
        printf("\n");       
    }
}

int CheckValues(int value, int lower_limit, int upper_limit)
{
    if (value < lower_limit || value > upper_limit)
    {
        printf("ERROR: rows, columns must be in range 2 to 10 and upperlimmit between 2 and 1000!\n"); 
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main()
{
    int rows = 0, cols = 0, upper_limit = 0;
    
    printf("\n=== Challenge Random Matrix ===\n\n");

    printf("\nEnter number of rows (min %d, max %d): ", MIN_ROWS, MAX_ROWS);
    scanf("%d", &rows);
    if (CheckValues(rows, MIN_ROWS, MAX_ROWS) == EXIT_FAILURE) { return EXIT_FAILURE; }

    printf("\nEnter number of columns (min %d, max %d): ", MIN_COLS, MAX_COLS);
    scanf("%d", &cols);
    if (CheckValues(cols, MIN_COLS, MAX_COLS) == EXIT_FAILURE) { return EXIT_FAILURE; }
    
    printf("\nEnter random number, upper limit (min %d, max %d): ", MIN_UPPER_LIMIT, MAX_UPPER_LIMIT);
    scanf("%d", &upper_limit);
    if (CheckValues(upper_limit, MIN_UPPER_LIMIT, MAX_UPPER_LIMIT) == EXIT_FAILURE) { return EXIT_FAILURE; }
        
    int matrix[rows][cols];                         // initialize a variable matrix
    
    srand(time(0));                                 // Use current time as seed for random generator
    create_matrix(rows, cols, upper_limit, matrix); // create a matrix with the user inputs
    printf("\nDirect form:\n"); 
    display_matrix(rows, cols, matrix, false);      // Print matrix in direct form
    printf("\nTransposed form:\n"); 
    display_matrix(rows, cols, matrix, true);       // Print matrix in transposed form

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
