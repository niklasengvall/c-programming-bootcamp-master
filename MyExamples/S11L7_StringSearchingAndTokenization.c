#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * String Searching and Tokenization
 * 
 *  - strchr: Locate first occurrence of character in string
 *  - strstr: Locate substring
 *  - strtok: Split string into tokens
 * 
 *  - Task 1: strchr
 *    Find all the occurrences of a char in a string and print:
 *    "This is a sample string"
 *        ^  ^   ^      ^
 * 
 *  - Task 2: strstr
 *    Find the first occurrence of a string in another string and print:
 *    "This is a sample string"
 *               ------
 * 
 *  - Task 3: strtok
 *    Store string tokens in a matrix and print:
 *    "This, is a. sample-string"
 *    [0] This
 *    [1] is
 *    [2] a
 *    [3] sample
 *    [4] string
 * 
 */

// Return no of found characters
int FindAllOccurrences(char str[], char c, int indexes[])
{
    int found = 0; // Holds an index where we find the character
    char *pstr = str; // Make a pointer to our string

    do
    {
        pstr = strchr(pstr, c); // Return a pointer where we find a character, if not found return NULL
        if (pstr) // Same as pstr != 0
        {
            indexes[found++] = pstr++ - str; // If we find a char store the index and increment index + in our searchstring
        }
    } while (pstr);
    return found;
}

void PrintOccurrences(char str[], int occurrencesIndexes[], int found)
{
    char pattern[strlen(str) + 1]; // Can't use sizeof(str) here
    memset(pattern, ' ', sizeof(pattern)); // Smart way to fill a memoryspace with a value
    for (int i = 0; i < found; i++)
    {
        pattern[occurrencesIndexes[i]] = '^'; 
    }
    pattern[sizeof(pattern) - 1] = '\0'; // For secure stringhandling
    printf("%s\n", str);
    printf("%s\n", pattern);
}

// Return -1 if sub isn't in str OR the starting index of sub in str
int FindSubstring(char str[], char sub[])
{
    char *psub = strstr(str, sub);
    return psub ? psub - str : -1; 
}

void PrintSubstring(char str[], char sub[], int index)
{
    printf("Find substring \"%s\":\n", sub); 
    printf("%s\n", str);
    if (index >= 0)
    {
        for (int i = 0; i < index + (int) strlen(sub); i++)
        {
            printf("%c", i < index ? ' ' : '-'); 
        }
    }    
}

//return the numbers of tokens found in the string
int TokenizeString(char str[], const char delimiters[], int tokMaxLen, char tokens[][tokMaxLen])
{
    int i;
    char *ptok = str;
    for (i = 0; ptok; i++) // run as long as ptok != NULL <=> end of string, no token found
    {
        ptok = strtok(i == 0 ? ptok : NULL, delimiters); // first time we return the address 
        strncpy(tokens[i], ptok, ptok ? tokMaxLen : 0); // Can't just asign an address, must copy the string if ptok != NULL and send the new address or NULL if no token found
    }
    return i - 1; // Number of token we found - 1 coz of i++ adds one extra number before it exits
}

void PrintTokens(int nTokens, int tokMaxLen, char tokens[][tokMaxLen], char str[], const char delimiters[])
{
    printf("\n\nTokenization with delimiters \"%s\":\n", delimiters);
    printf("%s\n", str); 
    for (int i = 0; i < nTokens; i++)
    {
        printf("[%d] %s\n", i, tokens[i]); 
    }   
}
int main()
{
    printf("\n=== String Searching and Tokenization ===\n\n"); 

    char str[] = "This, is a. sample-string";
    int occurrencesIndexes[sizeof(str)];
    int found = FindAllOccurrences(str, 'i', occurrencesIndexes);
    PrintOccurrences(str, occurrencesIndexes, found);

    char substring[] = "ring";
    int index = FindSubstring(str, substring);
    PrintSubstring(str, substring, index);

    const char delimiters[] = " ,.-";
    int tokMaxLen = sizeof(str);
    char tokens[tokMaxLen][tokMaxLen], strCopy[tokMaxLen];
    // Copy the original string before it will be ruined by TokenizeString and strtok
    strncpy(strCopy, str, tokMaxLen);

    int nTokens = TokenizeString(str, delimiters, tokMaxLen, tokens);
    PrintTokens(nTokens, tokMaxLen, tokens, strCopy, delimiters);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
