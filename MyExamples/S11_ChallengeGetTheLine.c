#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * === Get The Line ===
 * 
 * Implement a function that acquires a line from the console and has this prototype:
 * 
 *   int getLine(char dst[], int size)
 * 
 * Goals:
 *  - don't use scanf!
 *  - acquire a string up to the newline character
 *  - always put a null character at the end of the buffer
 *  - truncate the acquision to leave space at the end of the buffer for the null character
 *  - return the number of characters acquired, excluding the null character
 *  - implement a main loop that asks the user to insert a line, aquire it and print it
 *  - terminate the main loop when the users enters END
 */

#define MAX_BUFFER 100

void clear_stdin() // Truncate the buffer
{
    int c = ' ';
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int get_line(char dst[], int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            break;
        }
        dst[i] = (char) c;
    }
    if (i == size - 1)
    {
        clear_stdin();
    }
    dst[i] = '\0';
    return i;
}

int main()
{
    printf("\n=== Get The Line ===\n\n"); 

    char buffer[MAX_BUFFER];

    while (true)
    {
        printf("Enter a line: "); 
        int n = get_line(buffer, MAX_BUFFER);
        if (!strcmp(buffer, "END"))
        {
            break;
        }
        printf("[%d] %s\n", n, buffer); 
    } 
        
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
