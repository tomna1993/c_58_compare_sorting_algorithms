#include <cs50.h>
#include <stdio.h>

#define ARRAY_LENGTH 11

void print_array(int array[], int length);
void bubble_sort(int unsorted_array[], int array_length);

int main(int argc, string argv[])
{
    // Show user how to start the program if it was started incorrectly
    if (argc != 2)
    {
        printf ("Usage: ./[program_name] [text_file.txt]\n");
        printf ("or: time ./[program_name] [text_file.txt]\n");
        printf ("Example: time ./sort1 reversed10000.txt\n");
        return 1;
    }


    int unsorted_array[ARRAY_LENGTH] = {0, 4, 3, 10, 6, 2, 8, 7, 5, 9, 1};

    printf ("Unsorted: ");
    print_array(unsorted_array, ARRAY_LENGTH);

    bubble_sort(unsorted_array, ARRAY_LENGTH);

    printf ("Sorted: ");
    print_array(unsorted_array, ARRAY_LENGTH);
}

// Print array
void print_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf ("%i ", array[i]);
    }
    printf ("\n");
}

// Bubble sort algorithm
void bubble_sort(int unsorted_array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        for (int j = 0; j < array_length-1; j++)
        {
            if (unsorted_array[j] > unsorted_array[j + 1])
            {
                int temp = unsorted_array[j];
                unsorted_array[j] = unsorted_array[j + 1];
                unsorted_array[j + 1] = temp;
            }
        }
    }
}