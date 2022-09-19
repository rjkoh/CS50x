// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char word_copy[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[strlen(word)] = '\0';
    int hash_value = hash(word_copy);
    //create pointer to specific hash value in hash table
    node *cursor = table[hash_value];
    //go through linked list at hash value in table
    while (cursor != NULL)
    {
        //check if words match
        if (strcmp(word_copy, cursor->word) == 0)
        {
            return true;
        }
        
        //move cursor
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number, reference djb2, modified by https://gist.github.com/srushtikanade/b0612f537a15e1265f624dd2d946a917
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c = *word;
    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash *33 + c*/
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
int word_count = 0;
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    //scan dict for strings until eof
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        //copy word
        strcpy(n->word, word);
        int hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //go through indexes of table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
