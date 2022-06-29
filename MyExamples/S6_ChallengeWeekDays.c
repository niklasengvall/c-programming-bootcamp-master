#include <stdio.h>
#include <stdlib.h>

/**
 * === Days Of The Week ===
 * 
 * Goals:
 *  - declare an enum that lists all the days of the week
 *  - make sure it has the value of 1 on Monday
 *  - print monday and sunday values
 *  - get user input and store as a day enum
 *  - print a string with the name of the day
 * 
 */

int main()
{
    typedef enum {   // instead of enum weekdays we make an alias Weekday with typedef
        MONDAY = 1,  // The enum list starts with 1
        TUESDAY,      
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
           
    } Weekday;      // The new alias name Weekdays for this enum list

    Weekday userDayInput;

    printf("\n\n=== Days Of The Week ===\n\n"); 
    printf("Monday value = %d\n", MONDAY);   
    printf("Sunday value = %d\n", SUNDAY);   
 
    
    printf("Enter day number of the week: ");
    scanf("%u", &userDayInput);
    
    /*
    // Check if user inputs a negative value
    if (userDayInput < 1 || userDayInput > 7)
    {
        printf("WARNING: %d is an invalid number. You should enter a positive integer day value between 1 - 7!\n", userDayInput); 
        return EXIT_FAILURE;
    }
    */
    switch (userDayInput)
    {
    case MONDAY:
        printf("Day %d is MONDAY.\n", userDayInput); 
        break;
    case TUESDAY:
        printf("Day %d is TUESDAY.\n", userDayInput); 
        break;
    case WEDNESDAY:
        printf("Day %d is WEDNESDAY.\n", userDayInput); 
        break;
    case THURSDAY:
        printf("Day %d is THURSDAY.\n", userDayInput); 
        break;
    case FRIDAY:
        printf("Day %d is FRIDAY.\n", userDayInput); 
        break;
    case SATURDAY:
        printf("Day %d is SATURDAY.\n", userDayInput); 
        break;
    case SUNDAY:
        printf("Day %d is SUNDAY.\n", userDayInput); 
        break;   
    default:
        printf("WARNING: userDayInput has an unknown value of %d.\n", userDayInput); 
        break;
    }
    printf("\n\n=== ByteGarage ===\n\n"); 
    return EXIT_SUCCESS;
}
