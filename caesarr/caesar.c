#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototype
bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    int key, length;
    string plaintext;
    // Check if there is only 1 argument and that the argument is a digit
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar.c key\n");
        return 1;
    }
    key = atoi(argv[1]);
    plaintext = get_string("plaintext: ");
    length = strlen(plaintext);
    char ciphertext[length + 1];
    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
    }
    ciphertext[length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// function for checking if char(s) in string is a number i.e. from 0 -> 9
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

char rotate(char p, int k)
{
    char ci, pi, c;
    if (isupper(p))
    {
        pi = p - 65;
        ci = (pi + k) % 26;
        c = ci + 65;
    }
    else if (islower(p))
    {
        pi = p - 97;
        ci = (pi + k) % 26;
        c = ci + 97;
    }
    else
    {
        return p;
    }
    return c;
}