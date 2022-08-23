#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * === Get The Line Dynamically ===
 * 
 * Implement a function that acquires a line from the console and has this prototype:
 * 
 *   char *getLine_alloc(int *plen)
 * 
 * Goals:
 *  - don't use scanf!
 *  - acquire a string up to the newline character
 *  - always put a null character at the end of the buffer
 *  - return a newly allocated buffer containing the entire input buffer
 *  - if given, store the length of the input string in plen
 *  - plen may be NULL
 *  - return NULL if an error occurs
 *  - implement a main loop that asks the user to insert a line, aquire it and print it
 *  - terminate the main loop when the users enters END
 *  - in the main loop manage the allocated buffer
 * 
 * Tips: 
 *  - something might be useful to dynamically allocate memory
 * 
 */

char *getLineAlloc(int *plen)
{
    if (!plen) // Test if plen == NULL
    {
        // The user does not care about the lines length
        plen = malloc(sizeof(*plen)); // Allocate at least memory for storing one int value
        if (!plen) // We could not allocate memory
        {
            return NULL;
        }     
    }
    
    *plen = 0;
    char *line = NULL;
    int bufferSize = 0, input;
    const int allocBlockSize = 5; // Reallocate 5 chars at a time

    while (true)
    {
        input = getchar();
        
        if (bufferSize <= *plen) // If bufferSize is lesser than num of characters
        {
            // Resize the memory block!
            bufferSize += allocBlockSize; // Expand the buffer by 5 and reallocate memory
            char *reallocLine = realloc(line, bufferSize); // First time it will act as an malloc
        
            if (!reallocLine)   // Cannot do reallocation of memory
            {
                free(line);     // Free up previous memory
                return NULL;
            }
            
            // Reallocation done!
            line = reallocLine; // Let line buffer point to the new reallocated memory
        }

        if (input != '\n' && input != EOF)  // Let the user input until he/she hits ENTER or EOF state happens
        {
            line[(*plen)++] = (char) input; // Store the inputed char into the line buffer and increment *plens value that we point at
        }
        else
        {
            break;
        }   
    }
    
    line[*plen] = '\0'; // End the buffer string with a string NULL char
    return line;
}

int main()
{
    printf("\n=== Get The Line Dynamically ===\n\n"); 

    char *line = NULL;  // Our line buffer 
    int len = -1;       // Length of buffer 
    //int len = 0;
    do
    {
        printf("Enter a line (END to exit):\n"); 
        
        free(line); // No effect first time, second and afterwards, free up the allocated memory 
        // line = getLineAlloc(&len); // let the user input a line of text, dynnamically
        line = getLineAlloc(NULL); // let the user input a line of text, dynnamically
        
        if (line) // Memory successfully allocated
        {
            printf("%s (len=%d)\n", line, len); // Print the line buffer and it's length
        }
        else
        {
            printf("Cannot allocate memory!\n");
        }

    } while (line && strcmp(line, "END"));  // Exit if we got an memory allocation problem or user wrote END   

    if (line)                               // If memory is allocated in the heap, free up the memory
    {
        free(line);      
    }
    
    printf("Size of long: %lu \n", sizeof(long));
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}