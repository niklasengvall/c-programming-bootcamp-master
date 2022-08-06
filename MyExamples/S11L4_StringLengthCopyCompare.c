#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strlen
 * strcpy
 * strncpy
 * strcmp
 * strncmp
 */
int main()
{
    printf("\n=== String Length, Copy and Compare ===\n\n"); 

    char myString[] = "I love programming in C!";
    printf("The string: \"%s\"\n", myString); 

    // String Length
    int i;
    for (i = 0; myString[i] != '\0'; i++);
    printf("String lenght (from scratch): %d\n", i); 
    printf("Size of string: %ld\n", sizeof(myString)); 
    
    // String Length using build in function strlen in string.h
    printf("String lenght (build in): %ld\n", strlen(myString)); 

    // String copy: strcpy, strncpy
    char anotherString[] = "Programming is funny";
    printf("Before: \"%s\"\n", myString); 
    printf("After copy: \"%s\"\n", strcpy(myString, anotherString));

    char anotherLongString[] = "This is a dummy very very long string...";
    printf("Before: \"%s\"\n", myString); 
    printf("After copy: \"%s\"\n", strncpy(myString, "Hello", 3)); // The null char is missing

    //printf("After copy: \"%s\"\n", strncpy(myString, anotherLongString, strlen(myString) - 1));
    printf("Before: \"%s\"\n", myString);
    printf("After copy: \"%s\"\n", strncpy(myString, "Hello", sizeof(myString))); 

    printf("Before: \"%s\"\n", myString);
    strncpy(myString, anotherLongString, sizeof(myString));
    myString[sizeof(myString) - 1] = '\0'; // Always end a strin with null char
    printf("After copy: \"%s\"\n", myString); 

    // String compare: strcmp, strncmp (read only version)
    char str1[] = "abc";
    char str2[] = "abcaaaa";

    printf("strcmp %s, %s: %d\n",str1, str2, strcmp(str1, str2)); // Returns -value if str1 is < str2, +value if str1 > str2 and 0 if they are equal
    printf("strncmp %s, %s, %d chars: %d\n",str1, str2, 3, strncmp(str1, str2, 3)); // Compares exactly length

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
