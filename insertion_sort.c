#include <stdio.h>

#define ARRAY_LENGTH 11

void insertion_sort(int unsorted_list_array[], int array_length);

int main(void)
{
    int unsorted_array[ARRAY_LENGTH] = {1, 0, 4, 8, 10, 3, 9, 7, 2, 6, 5};

    insertion_sort(unsorted_array, ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf ("%i ", unsorted_array[i]);
    }
}

void insertion_sort(int unsorted_list_array[], int array_length)
{
    for (int i = 0; i < array_length-1; i++)
    {
        int j = i;
            
        while (j >= 0 && unsorted_list_array[j] > unsorted_list_array[j + 1])    
        {
            int tmp = unsorted_list_array[j + 1];
            unsorted_list_array[j + 1] = unsorted_list_array[j];
            unsorted_list_array[j] = tmp;

            j--;
        }
    }
}