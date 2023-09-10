// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

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

//word count
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int n = strlen(word);
    char buffer[n];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = toupper(word[i]);
    }
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
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
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file\n");
        return false;
    }

    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        printf("Could not find space to store word\n");
        return false;
    }

    while (fscanf(dict, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not load into memory\n");
            return false;
        }

        strcpy(n->word, word);
        int hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(dict);
    free(word);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count != 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false

bool unload(void)
{
    // TODO
    for (int i = 0; i <= N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}