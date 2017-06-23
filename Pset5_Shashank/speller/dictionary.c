/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define M 97
typedef struct node
{
    bool data;
    struct node* next[27];
}
node;
unsigned int dictionarySize = 0;
struct node* root = NULL;  
bool check(const char* word)
{
    unsigned int letter = '0';
    unsigned int index = 0;
    node* nextNode = root;
    while(letter != '\0')
    {
        letter = word[index];
        if (letter <= 90 && letter >= 65) 
        {
            letter |= 32;
        }
        if ((letter >= 97 && letter <= 122) || (letter == '\''))
        {
            if (letter == '\'')
            {
                letter = 26 + M;
            }
                 
            if (nextNode->next[letter - M] == NULL)
            {
                return false;
            }
            else
            {
                nextNode = nextNode->next[letter - M];
            }
        }
        index++;
    }
    return nextNode->data;
}
bool load(const char* dictionary)
{
    FILE* fpr = fopen(dictionary, "r");
     
    if (fpr == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    root = (node*) malloc(sizeof(node));
     
    unsigned int letter = 0;
    node* nextNode = root;
     
    while (letter != EOF)
    {
        letter = fgetc(fpr);
        if (letter != '\n' && letter != EOF)
        {
            if (letter == '\'')
            {
                letter = 26 + M;
            }
                 
            if (nextNode->next[letter - M] == NULL)
            {
                nextNode->next[letter - M] = (node*) malloc(sizeof(node));
            }
            nextNode = nextNode->next[letter - M];
        }
        else if (letter == '\n') 
        {
            nextNode->data = true;
            dictionarySize++;
            nextNode = root;
        }
    }
    fclose(fpr);
     
    return true;
}
unsigned int size(void)
{
    return dictionarySize;
}
void unloadNode(node* nextNode)
{
    for (int i = 0; i < 26; i++)
    {
        if (nextNode->next[i] != NULL)
        {
            unloadNode(nextNode->next[i]);
        }
    }
   free(nextNode);
}
bool unload(void)
{
    unloadNode(root);
    return true;
}