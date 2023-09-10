// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

int wordCount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *n = table[hash(word)];
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    /*
    int temp;
    char *copy = malloc(LENGTH + 1);

    strcpy(copy, word);
    for (int i = 0, c = strlen(word); i < c; i++)
    {
        temp = 0;

        if (copy[i] >= 'A' && copy[i] <= 'Z')
        {
            copy[i] += 32;
        }

        temp += copy[i] - 'a';
    }

    return temp % N;
    */

   int temp;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        temp = 0;
        temp += toupper(word[i]) - 'A';
    }
    int hash_value = temp % N;
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{
    // TODO
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Error opening dictionary\n");
        return false;
    }

    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        printf("not sufficient space for word\n");
        return false;
    }

    while (fscanf(inptr, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Error, not enough size for node\n");
            return false;
        }

        strcpy(n->word, word);
        int hashVal = hash(word);

        n->next = table[hashVal];
        table[hashVal] = n;

        wordCount++;
    }
    fclose(inptr);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    //base case
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *n = table[i]->next;
            free(table[i]);
            table[i] = n;
        }
    }
    return true;
}
