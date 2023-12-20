#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    // Prompt for start population size
    do {
        start = get_int("What is curent population size? ");

    } while (start < 9);

    // Promt user for end population size
    int end;
    do {
        end = get_int("Enter desired population size ");
    } while (end < start);

    // Calculate number of years until we reach threshold
    int years = 0;

    while (start < end) {
        start = start + (start/3) - (start/4);
        years++;
    };

    // Print number of years
    printf("Years: %i\n", years);
}
