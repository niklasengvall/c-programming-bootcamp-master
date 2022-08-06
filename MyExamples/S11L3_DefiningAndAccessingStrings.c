#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n=== Defining And Accessing Strings ===\n\n"); 

    // char fancy_string[10]; // Simplest declaration, we don't do anything with this string
    
    // Initializing different strings
    char str[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    char str2[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'n', 'o', ' ', '2',  '!'}; //  last char  will be null characters '\0' or in hex 0x00
    char str3[] = "Hello no 3!"; // An easier way to work with strings
    
    char str4[] = "This course is boring";

    // Initializing an 2D array of weekdays, observe that wednesday is 9 chars + null char equals 10 chars.
    char days[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    // Initialize an array of pointers to strings in memory
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    // Initialize an input array of 10 chars
    char inputStr[10];

    // Print all strings
    printf("%s\n", str);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);
    printf("%s\n", &str4[15]); // Prints "boring"
    printf("%.4s\n", str4);    // Prints the first 4 chars

    // Print weekdays
    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", days[i]); 
    }
    
    // Print months
    for (int i = 0; i < 12; i++)
    {
        printf("%s ", months[i]); 
    }

    printf("\nEnter a word, max 9 chars: "); 
    scanf("%s", inputStr);
    printf("You wrote: %s", inputStr);

    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
