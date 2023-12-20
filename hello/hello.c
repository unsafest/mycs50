#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // promt user for string, name
    string name = get_string("what is your name?\n");
    // print hello and user promt
    printf("Hello, %s\n", name);
}