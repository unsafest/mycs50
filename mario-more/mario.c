#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do {
        n = get_int("Height: ");
    } while (n < 1 || n > 8 );
    // Print rows
    for (int row = 0; row < n; row++) {
        // Print spaces
        for (int space = row; space < (n - 1); space++) {
            printf(" ");
        }
        // Print right half of pyramid
        for (int p = 0; p <= row; p++){
            printf("#");
        }
        // Space between pyramid halfs
        printf("  ");
        // Print left half of pyramid
        for (int hash = 0; hash <= row; hash++) {
            printf("#");
        }
        printf("\n");
    }

}