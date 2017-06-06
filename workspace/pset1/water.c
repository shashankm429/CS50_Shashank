#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int m;
    printf("Minutes: ");
    m= get_int();
    printf("Bottles: %d\n",m*12);
}