#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operator;
    double operandA, operandB, result = 0;

    printf("Enter the operator:   "); 
    scanf("%c", &operator);
    printf("Enter first operand:  "); 
    scanf("%lf", &operandA);
    printf("Enter second operand: "); 
    scanf("%lf", &operandB);
    printf("\n"); 
    
    int error = 0;

    switch (operator)
    {
        case '+':
            result = operandA + operandB;
            break;
        case '-':
            result = operandA - operandB;
            break;
        case '*':
            result = operandA * operandB;
            break;
        case '/':
            result = operandA / operandB;
            break;
        default:
            error = 1;
            break;
    }

    if (error)
    {
        printf("ERROR: unknown operator!\n"); 
    }
    else
    {
        printf("%.1lf %c %.1lf = %.1lf\n", operandA, operator, operandB, result); 
        printf("\n\n=== ByteGarage ===\n\n"); 
    }
    return EXIT_SUCCESS;
}
