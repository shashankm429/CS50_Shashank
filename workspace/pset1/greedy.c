#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int coins[] = {25, 10, 5, 1};
    float change;
    int Change;
    int coinsNumber = 0;
    
    do
    {
        printf("How much change is owed?: \n");
        change = GetFloat();
    } while (change < 0);
    
    Change = round(change * 100);
    
    for (int i = 0; i < 4; i++)
    {
        int count = 0;
        count = Change / coins[i];
        Change = Change - ( count * coins[i] );
        coinsNumber = coinsNumber + count;
    }
    
    printf("%i\n", coinsNumber);
}