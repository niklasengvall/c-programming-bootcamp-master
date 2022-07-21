// #include <stdio.h>  // Result is we miss printf 
#include <stdlib.h>

// double average(double a, double b); // Out commented a good function declaration

int main()
{
    int num = 12; // missing semicolon

    if (num < 0) // using semicolon ";" after an if, compiler with -Wall detects this, otherwise it runs the printf statement
    {
        printf("num is < 0\n"); 
    }

    if (num == 5) // We use one assign operator "=", instead of more correct comparing operator, its stated as true
    {
        printf("num is equal to 5\n"); 
    }
    
    // logical error, we want to print up to 12, it's a range problem
    for (int i = 0; i <= num; i++) // < should be <=
    {
        printf("%d\n", i); 
    }

    double a = 1, b = 2, c = 3;
    
    // double avg = average(average(a, b), c); Gives 2.2, should be 2, its a logical problem (1 + 2) /2 = (1.5 + 3) /2 = 2.25
    double avg = (a + b + c) / 3;
    printf("average(%.1f, %.1f, %.1f) = %.1f \n", a, b, c, avg); 

    printf("average(%.1f, %.1f) = %.1d \n", a, b, average(a, b)); // Function is not declarated, if you cange it to int it will work but DON'T 
    // The third %.1d should be %.1f
    
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}

int average(double a, double b)
{
    return (a + b) / 2;
}
