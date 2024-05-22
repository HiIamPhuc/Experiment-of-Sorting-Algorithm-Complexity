# Experiment-of-Sorting-Algorithm-Complexity

<h2>Description</h2>

<h3>Algorithms implemented:</h3>
<p>All the sorting algorithms we have implemented for our research are Selection Sort, Insertion Sort, Bubble Sort, Shaker Sort, Shell Sort, Heap Sort, Merge Sort, Quick Sort, Counting Sort, Radix Sort, and Flash Sort.</p>

<h3>Experiments:</h3>
The experiments necessary for this project are conducted following the below scenario:<br>
&ensp;for each Data Order S1<br>
&ensp;&ensp;for each Data Size S2<br>
&ensp;&ensp;&ensp;for each Sorting Algorithm S3<br>
&ensp;&ensp;&ensp;&ensp;1. Create an array with Data Order S1 and Data Size S2<br>
&ensp;&ensp;&ensp;&ensp;2. Sort the created array using the Sorting Algorithm S3, while:<br>
&ensp;&ensp;&ensp;&ensp;&ensp;+ Measuring the running time (in milliseconds), and<br>
&ensp;&ensp;&ensp;&ensp;&ensp;+ Counting the number of comparisons in the algorithm<br>
&ensp;&ensp;&ensp;&ensp;3. Take note of S1, S2, S3, running time and number of comparisons<br>
&ensp;&ensp;&ensp;end for<br>
&ensp;&ensp;end for<br>
&ensp;end for<br>

<h3>Data Order:</h3>
<p>Examine the selected sorting algorithms on different data arrangements, including Sorted data (in ascending order), Nearly sorted data, Reverse sorted data, and Randomized data. See DataGenerator.cpp for more information.</p>

<h3>Data Size:</h3>
<p>Examine the selected sorting algorithms on data of the following sizes: 10,000, 30,000, 50,000, 100,000, 300,000, and 500,000 elements.</p>


<h2>Usage</h2>
<h3>Input arguments:</h3> 
The following arguments are applied for both modes.<br>
&ensp;a. Mode:<br>
&ensp;&ensp;• -a: Algorithm mode<br>
&ensp;&ensp;• -c: Comparison mode<br>
&ensp;b. Algorithm name: Lowercase, words are connected by "-" (Ex: selection-sort, binaryinsertion-sort, ...)<br>
&ensp;c. Input size:<br>
&ensp;d. Integer (≤ 1; 000; 000)<br>
&ensp;e. Input order:<br>
&ensp;&ensp;• -rand: randomized data<br>
&ensp;&ensp;• -nsorted: nearly sorted data<br>
&ensp;&ensp;• -sorted: sorted data<br>
&ensp;&ensp;• -rev: reverse sorted data<br>
&ensp;f. Given input (file): Path to the input file. The file format is as follows.<br>
&ensp;&ensp;• 1st line: an integer n, indicating the number of elements in the input data<br>
&ensp;&ensp;• 2nd line: n integers, separated by a single space.<br>
&ensp;g. Output parameters<br>
&ensp;&ensp;• -time: algorithms’s running time.<br>
&ensp;&ensp;• -comp: number of comparisons.<br>
&ensp;&ensp;• -both: both above options.<br>

<h3>Output specifications:</h3>
<p>You must first compile your source codes into an executable file (.exe) that can be triggered by using command line.</p>

<h3>1. Algorithm mode:</h3> 
<p>In this mode, you run a specified sorting algorithm on the input data, which is either given or generated automatically, and receive the resulting running time and/or the number of comparisons.</p>

&ensp;• Command 1: Run a sorting algorithm on the given input data.<br>
&ensp;&ensp;– Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]<br>
&ensp;&ensp;– Ex: a.exe -a radix-sort input.txt -both<br>

&ensp;• Command 2: Run a sorting algorithm on the data generated automatically with specified size and order.<br>
&ensp;&ensp;– Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]<br>
&ensp;&ensp;– Ex: a.exe -a selection-sort 50 -rand -time<br>

&ensp;• Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.<br>
&ensp;&ensp;– Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]<br>
&ensp;&ensp;– Ex: a.exe -a binary-insertion-sort 70000 -comp<br>

<h3>2. Comparison mode:</h3> 
<p>In this mode, you run TWO specified sorting algorithms on the input data, which is either given or generated automatically, and receive the resulting running times and/or numbers of comparisons.</p>
&ensp;• Command 4: Run two sorting algorithms on the given input.<br>
&ensp;&ensp;– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]<br>
&ensp;&ensp;– Ex: a.exe -c heap-sort merge-sort input.txt <br><br>

&ensp;• Command 5: Run two sorting algorithms on the data generated automatically.<br>
&ensp;&ensp;– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]<br>
&ensp;&ensp;– Ex: a.exe -c quick-sort merge-sort 100000 -nsorted<br>

<h3>Writing files:</h3> 
<p>Besides the console output described above, the program writes down the corresponding input(s) or output(s).</p>
&ensp;• For Command 1 and Command 2: Write down the sorted array to the "output.txt" file.<br>
&ensp;• For Command 2 and Command 5: Write down the generated input to the "input.txt" file.<br>
&ensp;• For Command 3: Write down all four generated inputs:<br>
&ensp;&ensp;– "input_1.txt": random order data<br>
&ensp;&ensp;– "input_2.txt": nearly sorted data<br>
&ensp;&ensp;– "input_3.txt": sorted data<br>
&ensp;&ensp;– "input_4.txt": reversed data<br><br>
    
<p>The file format (for both input and output files) is as follows.</p>
&ensp;• 1st line: an integer n, indicating the number of elements in the input data<br>
&ensp;• 2nd line: n integers, separated by a single space.
