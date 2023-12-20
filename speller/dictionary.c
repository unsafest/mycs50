// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Word counter
int word_counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        // strcasecmp compares strings without considering case
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: hash function
    unsigned int hash = 0;
    // Iterates over each character in the word.
    for (int i = 0, n = strlen(word); i < n; i++)
    {
         // Converts the character to lowercase and adds its ASCII value to the hash.
        hash += tolower(word[i]);
    }
    // Returns the hash value modulo the size of the hash table to ensure it fits within the table.
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open file with read permition
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("unable to open file\n");
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        else
        {
            // copy word into node
            strcpy(n->word, word);
            // Hashes the word to get an index for the hash table.
            int index = hash(word);
            // Sets the node's next pointer to point to the current first node in the list at the hashed index.
            n->next = table[index];
            // Sets the new node as the first node in the list at the hashed index.
            table[index] = n;
        }
        word_counter++;
    }
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO return counter
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // for each index in the hash table
    for (int i = 0; i < N; i++)
    {
        // Sets a cursor to the first node in the list at the current index
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // Stores the current node in a temporary variable
            node *temp = cursor;
            // Moves the cursor to the next node in the list
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
