#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string plainText;
     
    int keyLength;
    string key;
    
    if (argc != 2)
    {
        printf ("No command line argument passed \n");
        return 1; 
    }
    else
    {
        keyLength = strlen(argv[1]);
        key = argv[1];
        
        for (int i = 0; i < keyLength; i++)
        {
            if (!isalpha(key[i]))
            {
                printf ("key contains non-alphabetical character\n");
                return 1;  
            }
            else
            {
                if (isupper(key[i]))
                {
                    key[i] = key[i] - 65;
                }
                else if(islower(key[i]))
                {
                    key[i] = key[i] - 97;
                }
            }
        }
    }
    printf("plaintext: ");
    plainText = GetString();
    
    int j = 0;
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] = (((plainText[i] - 65) + key[j]) % 26) + 65;
            j++;
        }
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            
            plainText[i] = (((plainText[i] - 97) + key[j]) % 26) + 97;
            j++;
        }
        
        if (j == keyLength)
        {
            j = 0;
        }
    }
    printf("ciphertext: %s",plainText);
    printf("\n");
    return 0; 
}
