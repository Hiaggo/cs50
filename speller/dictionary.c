// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 300;

// Hash table
node *table[N];

// Size
int _size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    if (table[index] == NULL)
    {
        return false;
    }
    else
    {
        if (strcasecmp(word, table[index]->word) == 0)
        {
            return true;
        }
        else
        {
            for (node *i = table[index]->next; i != NULL; i = i->next)
            {
                if (strcasecmp(word, i->word) == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int g = 31;
    int hash = 0;
    char dup[strlen(word)];
    strcpy(dup, word);
    for (int i = 0; i < strlen(word); i++)
    {
        dup[i] = tolower(word[i]);
        hash = (g * hash + dup[i]) % N;
    }
    return hash;

    // Modified version of "Hashes 4 Hash Functions for Strings" - https://www.youtube.com/watch?v=jtMwp0FqEcg

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (!dict)
    {
        return false;
    }

    char word[LENGTH + 1];
    int index = 0;

    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }

        strcpy(n->word, word);
        _size++;
        n->next = NULL;
        index = hash(word);

        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return _size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i];
            while (cursor)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
        }
    }

    return true;
}
