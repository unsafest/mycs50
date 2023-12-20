#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
bool only_digits(string s);

int main(int argc, string argv[])
{
    // Check if there is only 1 argument and that the argument is a digit
    // by calling a function that returns true if argv1 is number and false if not
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar.c key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + key) % 26 + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

// function for checking if char(s) in string is a number
bool only_digits(string s)
{
    int length;
    length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
