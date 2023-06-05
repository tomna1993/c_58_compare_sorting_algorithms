#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_number(string text);
void print_array(int array[], int array_length);
void merge_sort(int array[], int array_length);
void sort_halves(int unsorted[], int sorted[], int start_index, int end_index);
void merge_halves(int unsorted[], int sorted[], int start_index, int mid_index, int end_index);
void copy_array(int from[], int to[], int start, int end);

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

    int list_length = find_number(text_file);

    int unsorted_numbers[list_length];

    // Read file into array
    FILE *file_handle = fopen (text_file, "r");

    if (file_handle == NULL)
    {
        printf ("Cannot open file!\n");
        return 1;
    }

    for (int i = 0; i < list_length; i++)
    {
        fscanf(file_handle, "%i", &unsorted_numbers[i]);
    }

    // The sorted array will be placed back into unsorted array
    merge_sort(unsorted_numbers, list_length);

    // print_array(unsorted_numbers, list_length);

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

void merge_sort(int array[], int array_length)
{  
    int unsorted[array_length];

    // The unsorted array (work array) must contain the same elements as
    // the array we want to sort
    copy_array(array, unsorted, 0, array_length);

    sort_halves(unsorted, array, 0, array_length - 1);

    return;
}

void sort_halves(int unsorted[], int sorted[], int start_index, int end_index)
{
    // Define base-case / exit condition
    // Consider list already sorted or list has just one number
    if (start_index >= end_index)
    {
        return;
    }

    int mid_index = (start_index + end_index) / 2;

    // Sort left source
    sort_halves(unsorted, sorted, start_index, mid_index);

    // Sort rigth source
    sort_halves(unsorted, sorted, mid_index + 1, end_index);

    // Merge left and right back into unsorted array
    merge_halves(unsorted, sorted, start_index, mid_index + 1, end_index);

    return;
}

void merge_halves(int unsorted[], int sorted[], int start_index, int mid_index, int end_index)
{
    int count = start_index;
    int start = start_index;

    int mid = mid_index;

    while (start < mid_index && mid <= end_index)
    {
        // Always check unsorted list, later we must copy the sorted array
        // back into the unsorted
        if (unsorted[start] <= unsorted[mid])
        {
            sorted[count] = unsorted[start];
            start++;
        }
        else
        {
            sorted[count] = unsorted[mid];
            mid++;
        }

        count++;
    }

    //
    while (start < mid_index) 
    {
        sorted[count++] = unsorted[start++];  
    }

    while (mid <= end_index)
    {
        sorted[count++] = unsorted[mid++];
    }

    // Copy the sorted part of the list back to unsorted
    copy_array(sorted, unsorted, start_index, end_index + 1);

    // print_array(unsorted, end_index + 1);

    return;
}

void copy_array(int from[], int to[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        to[i] = from[i]; 
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