# c_58_compare_sorting_algorithms

## DESCRIPTION

Analyze three sorting programs to determine which algorithms they use.

### BACKGROUND

- Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.
- Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.
- Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

## Instructions

C programs: sort1, sort2, and sort3 implements a different sorting algorithm: selection sort, bubble sort, or merge sort (though not necessarily in that order!). The task is to determine which sorting algorithm is used by each file without looking into their source code.

- To assess which sort implements which algorithm, run the sorts on different lists of values.
- Multiple .txt files are provided, these files contain n lines of values, either reversed, shuffled, or sorted. For example, 'reversed10000.txt' contains 10000 lines of numbers that are reversed from 10000, while 'random10000.txt' contains 10000 lines of numbers that are in random order.
- To run the sorts on the text files, in the terminal, run:

  ```bash
  ./[program_name] [text_file.txt]
  ```

  For example, to sort 'reversed10000.txt' with 'sort1', run:

  ```bash
  ./sort1 reversed10000.txt
  ```

- You may find it helpful to time your sorts. To do so, run:

  ```bash
  time ./sort1 reversed10000.txt
  ```

  For example, you could run:
  
  ```bash
  time ./sort1 reversed10000.txt
  ```
  
  to run 'sort1' on 10,000 reversed numbers. At the end of your terminal’s output, you can look at the real time to see how much time actually elapsed while running the program.

Record your answers for each program, by filling in the blanks marked in the TODO list.

## TODO

sort1 uses:

How do you know?:

sort2 uses:

How do you know?:

sort3 uses:

How do you know?:
