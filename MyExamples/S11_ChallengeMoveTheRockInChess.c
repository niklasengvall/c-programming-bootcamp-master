#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * === Move The Rock! ===
 * 
 * Print out the positions the rook can move in the chess game
 * 
 * Goals:
 *  - Create a function with these parameters as input:
 *    - the current position as a string (e.g. "d5")
 *    - an array of characters to store possible moves
 *  - Store the correct positions in the array, separated by space
 *  - Implement at least 2 versions of the algorithm!
 */

void RookPoor(char currentPosition[], char outputBuffer[])
{
    const char cols[] = "abcdefgh";
    const char rows[] = "12345678";

    char curCol = currentPosition[0];
    char curRow = currentPosition[1];
    char *dst = outputBuffer;

    // Store allowed horizontal movements in outputBuffer
    for (const char *p = cols; *p; p++)
    {
        if (*p != curCol)
        {
            *dst++ = *p;
            *dst++ = curRow;
            *dst++ = ' ';
        }
    }
    // Store allowed vertical movements in outputBuffer
    for (const char *p = rows; *p; p++)
    {
        if (*p != curRow)
        {
            *dst++ = curCol;
            *dst++ = *p;
            *dst++ = ' ';
        }
    }   
    *dst = '\0';
}

void RookGood(char currentPosition[], char outputBuffer[])
{
    const char cols[] = "abcdefgh";
    const char rows[] = "12345678";

    char curCol = currentPosition[0];
    char curRow = currentPosition[1];
    char *dst = outputBuffer;

    for (const char *pc = cols, *pr = rows; *pc || *pr; *pc ? pc++ : pr++)
    {
        if (*pc != curCol && *pr != curRow)
        {
            *dst++ = *pc ? *pc : curCol;
            *dst++ = *pc ? curRow : *pr;
            *dst++ = ' ';
        }
    }
    *dst = '\0';
}

void RookGoodAlt(char currentPosition[], char outputBuffer[])
{
    const char colsRows[] = "abcdefgh12345678";

    char curCol = currentPosition[0];
    char curRow = currentPosition[1];
    char *dst = outputBuffer;

    for (const char *p = colsRows; *p; p++)
    {
        if (*p != curRow && *p != curCol)
        {
            *dst++ = isdigit(*p) ? curCol : *p; // Get the correct column
            *dst++ = isdigit(*p) ? *p : curRow; // Get the correct row
            *dst++ = ' ';
        }
    }
    *dst = '\0';
}

void PrintBuffer(const char pos[], const char buffer[])
{
    printf("Current position: %s\n", pos);
    printf("You can move to:  %s\n\n", buffer);
}
int main()
{
    printf("\n=== Move The Rook! ===\n\n"); 
    
    char pos[] = "d5";
    char buffer[100];

    RookPoor(pos, buffer);
    PrintBuffer(pos, buffer);

    RookGood(pos, buffer);
    PrintBuffer(pos, buffer);

    RookGoodAlt(pos, buffer);
    PrintBuffer(pos, buffer);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
