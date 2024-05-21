# Experiment-of-Sorting-Algorithm-Complexity

## Description
### Algorithms implemented:
  All the sorting algorithms we have implemented for our research are Selection Sort, Insertion Sort, Bubble Sort, Shaker Sort, Shell Sort, Heap Sort, Merge Sort, Quick Sort, Counting Sort, Radix Sort, and Flash Sort.

### Experiments:
The experiments necessary for this project are conducted following the below scenario:
  for each Data Order S1
    for each Data Size S2
      for each Sorting Algorithm S3
        1. Create an array with Data Order S1 and Data Size S2
        2. Sort the created array using the Sorting Algorithm S3, while:
            + Measuring the running time (in milliseconds), and
            + Counting the number of comparisons in the algorithm
        3. Take note of S1, S2, S3, running time and number of comparisons
      end for
    end for
  end for
#### Data Order:
  Examine the selected sorting algorithms on different data arrangements, including Sorted data (in ascending order), Nearly sorted data, Reverse sorted data, and Randomized data. See DataGenerator.cpp for more information.
#### Data Size:
Examine the selected sorting algorithms on data of the following sizes: 10,000, 30,000, 50,000, 100,000, 300,000, and 500,000 elements.

## Usage
### Input arguments: 
The following arguments are applied for both modes.
  a. Mode:
    • -a: Algorithm mode
    • -c: Comparison mode
  b. Algorithm name: Lowercase, words are connected by "-" (Ex: selection-sort, binaryinsertion-sort, ...)
  c. Input size:
  d. Integer (≤ 1; 000; 000)
  e. Input order:
    • -rand: randomized data
    • -nsorted: nearly sorted data
    • -sorted: sorted data
    • -rev: reverse sorted data
  f. Given input (file): Path to the input file. The file format is as follows.
    • 1st line: an integer n, indicating the number of elements in the input data
    • 2nd line: n integers, separated by a single space.
  g. Output parameters
    • -time: algorithms’s running time.
    • -comp: number of comparisons.
    • -both: both above options.

### Output specifications:
You must first compile your source codes into an executable file (.exe) that can be triggered by using command line.

#### 1. Algorithm mode: 
In this mode, you run a specified sorting algorithm on the input
data, which is either given or generated automatically, and receive the resulting running time
and/or the number of comparisons.

  • Command 1: Run a sorting algorithm on the given input data.
    – Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
    – Ex: a.exe -a radix-sort input.txt -both

  • Command 2: Run a sorting algorithm on the data generated automatically with specified size and order.
    – Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
    – Ex: a.exe -a selection-sort 50 -rand -time

  • Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
    – Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
    – Ex: a.exe -a binary-insertion-sort 70000 -comp

#### 2. Comparison mode: 
In this mode, you run TWO specified sorting algorithms on the input data, which is either given or generated automatically, and receive the resulting running times and/or numbers of comparisons.
  • Command 4: Run two sorting algorithms on the given input.
    – Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
    – Ex: a.exe -c heap-sort merge-sort input.txt

  • Command 5: Run two sorting algorithms on the data generated automatically.
    – Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
    – Ex: a.exe -c quick-sort merge-sort 100000 -nsorted

### Writing files: 
Besides the console output described above, the program writes down the
corresponding input(s) or output(s).
  • For Command 1 and Command 2: Write down the sorted array to the "output.txt" file.
  • For Command 2 and Command 5: Write down the generated input to the "input.txt" file.
  • For Command 3: Write down all four generated inputs:
    – "input_1.txt": random order data
    – "input_2.txt": nearly sorted data
    – "input_3.txt": sorted data
    – "input_4.txt": reversed data
    
The file format (for both input and output files) is as follows.
  • 1st line: an integer n, indicating the number of elements in the input data
  • 2nd line: n integers, separated by a single space.
