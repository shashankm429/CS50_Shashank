#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    int height;
    
    do
    {
        printf("Height: ");
        height = GetInt();
        if (height == 0)
        {
            return 0;
        }
    } while (height < 0 || height > 23);
    for (int i = 1; i <= height; i++)
    {   
        
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        
        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    } 
}