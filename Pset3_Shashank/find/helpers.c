/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
     int low=0, high= n-1, mid;
    
    while(low<=high)
    {
        mid = (low + high)/2;
        if(values[mid] < value)
        {
            low = mid + 1; 
        }
        else if(values[mid] == value)
        {
            return true;
        }
        else if(values[mid] > value)
        {
            high = mid-1;
        }
    }
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int temp = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(values[i]>values[j])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    return;
}
