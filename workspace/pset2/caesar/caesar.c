#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string plainText;
    
    if (argc != 2)
    {
        printf ("No command line argument passed \n");
        return 1; 
    }
    
    int key = atoi(argv[1]);
    printf("plaintext: ");
    plainText = GetString();
    
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] = (((plainText[i] - 65) + key) % 26) + 65;
        }
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            
            plainText[i] = (((plainText[i] - 97) + key) % 26) + 97;
        }
    }
    
    printf("ciphertext: %s",plainText);
    printf("\n");
    return 0;
}