#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // Prompt user for integer and store value in integer variable n
    do
    {
        n = get_int("How many block high do you want your pyramid to be? ");
    }
    // Check for valid input, beilng an positive integer betwen 1 and 8
    while (n > 8 || n < 1);

    // printf("Height: %i\n", n);

    // For evry row print new line, number of row is = to n, which is a number promted by user
    for (int row = 0; row < n; row++)
    {
        // This nested loop handles space, number of spaces = rows - 1
        for (int i = row; i < (n - 1); i++)
        {
            printf(" ");
        }
        // This nested loop handles culims, print # +1 for evry row
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
    return (0);
}