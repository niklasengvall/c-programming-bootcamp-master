#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a + b;
}
/**
 * @brief if value > 0 => accumulate value in accumulator else => do nothiung
 * 
 * @param accumulator the original value we want to increase with the parameter value as a const address to int
 * @param value how much we want to add to accumulator
 * @return int  0 (SUCCESS) OR -1 (FAIL)
 */
int accumulate(int *const accumulator, int value) // Pointer to const address
{
    if (value > 0)
    {
        *accumulator += value;
        return 0;
    }
    else
    {
        return -1;
    }
}

void AccumulateWrapper(int *const accumulator, int value)
{
    if (accumulate(accumulator, value))
    {
        printf("Warning! Value = %d\n", value); 
    }
}

void PrintStudents(int students)
{
    printf("Students = %d\n", students); 
}

int main()
{
    printf("\n=== Functions And Pointers ===\n"); 

    int girls = 12, boys = 9;
    int students = sum(girls, boys);
    
    PrintStudents(students);

    int class_1 = 28, class_2 = 19, class_3 = -1;
    int accumulator = 0;

    AccumulateWrapper(&accumulator, class_1);
    AccumulateWrapper(&accumulator, class_2);
    AccumulateWrapper(&accumulator, class_3);
    
    printf("Accumulator = %d\n", accumulator); 
    printf("\n\n=== ByteGarage ===\n\n");
    return EXIT_SUCCESS;
}
