#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;
    int length;
    
    name = GetString();
    
    length = strlen(name);
   
    printf("%c",toupper(name[0]));
    for (int i = 0; i < length; i++)
    {
      
        if (name[i] == ' ')
        {
            printf("%c",toupper(name[i + 1]));
        }
    }
    printf("\n");
}