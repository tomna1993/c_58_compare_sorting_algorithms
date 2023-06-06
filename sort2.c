#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_number(string text);
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

    string text_file = argv[1];

    const int list_length = find_number(text_file);

    int unsorted_array[list_length];

    // Read file into array

    FILE *file_handle = fopen (text_file, "r");

    if (file_handle == NULL)
    {
        printf ("Cannot open file!\n");
        return 1;
    }

    for (int i = 0; i < list_length; i++)
    {
        fscanf(file_handle, "%i", &unsorted_array[i]);
    }

    bubble_sort(unsorted_array, list_length);

    // print_array(unsorted_array, list_length);

    return 0;
}

int find_number(string text)
{
    char number[10];
    int j = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            continue;
        }

        if (isdigit(text[i]))
        {
            number[j++] = text[i];   
        }
    }

    return atoi(number);
}

// Bubble sort algorithm
void bubble_sort(int unsorted_array[], int array_length)
{
    bool sorted;

    for (int i = 0; i < array_length; i++)
    {
        // sorted remains true if the list is already sorted
        sorted = true;

        for (int j = 0; j < array_length - 1 - i; j++)
        {
            if (unsorted_array[j] > unsorted_array[j + 1])
            {
                int temp = unsorted_array[j];
                unsorted_array[j] = unsorted_array[j + 1];
                unsorted_array[j + 1] = temp;

                // The list is not sorted yet, values in the array was replaced
                sorted = false;
            }
        }

        // List sorted
        if (sorted)
        {
            return;
        }
    }

    return;
}

void print_array(int array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        if (i % 20 == 0)
        {
            printf ("\n");
        }
        printf ("%i ", array[i]);
    }
    printf ("\n");

    return;
}