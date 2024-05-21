#include "Header.h"
// General

typedef unsigned long long (*sort_func_Comparison)(int *, int);
typedef double (*sort_func_RunningTime)(int *, int);
sort_func_Comparison sorting_algo_Comparison[] = {SelectionSort_Comparison,
												  InsertionSort_Comparison,
												  BubbleSort_Comparison,
												  HeapSort_Comparison,
												  MergeSort_Comparison,
												  QuickSort_Comparison,
												  RadixSort_Comparison,
												  ShakerSort_Comparison,
												  ShellSort_Comparison,
												  CountingSort_Comparison,
												  FlashSort_Comparison};
sort_func_RunningTime sorting_algo_RunningTime[] = {SelectionSort_RunningTime,
													InsertionSort_RunningTime,
													BubbleSort_RunningTime,
													HeapSort_RunningTime,
													MergeSort_RunningTime,
													QuickSort_RunningTime,
													RadixSort_RunningTime,
													ShakerSort_RunningTime,
													ShellSort_RunningTime,
													CountingSort_RunningTime,
													FlashSort_RunningTime};

void algorithm(int *a, int n, const char *name, const char *param, result &x)
{
	const char *temp[] = {"selection-sort",
						  "insertion-sort",
						  "bubble-sort",
						  "heap-sort",
						  "merge-sort",
						  "quick-sort",
						  "radix-sort",
						  "shaker-sort",
						  "shell-sort",
						  "counting-sort",
						  "flash-sort"};

	for (int i = 0; i < 11; i++)
	{
		if (strcmp(name, temp[i]) == 0)
		{
			if (strcmp(param, "-time") == 0)
			{
				x.time = sorting_algo_RunningTime[i](a, n);
				x.cmpNum = 0;
			}
			else if (strcmp(param, "-comp") == 0)
			{
				x.time = 0;
				x.cmpNum = sorting_algo_Comparison[i](a, n);
			}
			else if (strcmp(param, "-both") == 0)
			{
				int *b = new int[n];
				for (int i = 0; i < n; i++)
					b[i] = a[i];

				x.time = sorting_algo_RunningTime[i](a, n);
				x.cmpNum = sorting_algo_Comparison[i](b, n);

				delete[] b;
			}
		}
	}
}

void getDataFromFile(const char *file, int *&a, int &n)
{
	fstream myfile;
	myfile.open(file, ios::in);
	if (!myfile.is_open())
	{
		std::cout << "Cannot open file!";
		exit(1);
	}
	myfile >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		myfile >> a[i];
	}
	myfile.close();
}

void writeDataToFile(const char *file, int *a, int n)
{
	fstream myfile;
	myfile.open(file, ios::out);
	myfile << n << endl;
	for (int i = 0; i < n; i++)
	{
		myfile << a[i] << " ";
	}
	myfile.close();
}

// COMMAND PROMPT 1
void command_1(int argc, const char *argv[])
{
	// declare variables
	int size;
	int *a;
	result x;

	// process
	getDataFromFile(argv[3], a, size);
	algorithm(a, size, argv[2], argv[4], x);
	writeDataToFile("output.txt", a, size);

	// print results
	std::cout << "ALGORITHM MODE" << endl;
	std::cout << "Algorithm: " << argv[2] << endl;
	std::cout << "Input file: " << argv[3] << endl;
	std::cout << "Input size: " << size << endl;
	std::cout << "--------------------------------------------" << endl;
	if (strcmp(argv[4], "-time") == 0)
	{
		std::cout << "Running time: " << x.time << endl;
	}
	if (strcmp(argv[4], "-comp") == 0)
	{
		std::cout << "Comparisions: " << x.cmpNum << endl;
	}
	if (strcmp(argv[4], "-both") == 0)
	{
		std::cout << "Running time: " << x.time << endl;
		std::cout << "Comparisions: " << x.cmpNum << endl;
	}

	delete[] a;
}

// COMMAND PROMPT 2
void command_2(int argc, const char *argv[])
{
	// declare variables
	int size = atoi(argv[3]);
	int *n = new int[size];
	result x;
	const char *order_temp[] = {"-rand", "-nsorted", "-sorted", "-rev"};
	const char *order[] = {"Randomized", "Nearly Sorted", "Sorted", "Reversed"};

	// process
	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(argv[4], order_temp[i]) == 0)
		{
			GenerateData(n, size, i);
			break;
		}
	}

	writeDataToFile("input.txt", n, size);
	algorithm(n, size, argv[2], argv[5], x);
	writeDataToFile("output.txt", n, size);

	// print
	std::cout << "ALGORITHM MODE" << endl;
	std::cout << "Algorithm: " << argv[2] << endl;
	std::cout << "Input size: " << size << endl;
	std::cout << "Input order: " << order[i] << endl;
	std::cout << "--------------------------------------------" << endl;
	if (strcmp(argv[5], "-time") == 0)
	{
		std::cout << "Running time: " << x.time << endl;
	}
	if (strcmp(argv[5], "-comp") == 0)
	{
		std::cout << "Comparisions: " << x.cmpNum << endl;
	}
	if (strcmp(argv[5], "-both") == 0)
	{
		std::cout << "Running time: " << x.time << endl;
		std::cout << "Comparisions: " << x.cmpNum << endl;
	}

	delete[] n;
}

// COMMAND PROMPT 3
void command_3(int argc, const char *argv[])
{
	// declare variables
	int size = atoi(argv[3]);
	int *a = new int[size];
	result x;
	const char *order[] = {"Randomized", "Nearly Sorted", "Sorted", "Reversed"};
	// "input_1.txt": random order data
	// "input_2.txt": nearly sorted data
	// "input_3.txt": sorted data
	// "input_4.txt": reversed data
	const char *fileName[] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};

	// print
	std::cout << "ALGORITHM MODE" << endl;
	std::cout << "Algorithm: " << argv[2] << endl;
	std::cout << "Input size: " << size << endl;

	for (int i = 0; i < 4; i++)
	{
		// process
		GenerateData(a, size, i);
		writeDataToFile(fileName[i], a, size);
		algorithm(a, size, argv[2], argv[4], x);

		// print results
		std::cout << "Input order: " << order[i] << endl;
		std::cout << "--------------------------------------------" << endl;
		if (strcmp(argv[4], "-time") == 0)
		{
			std::cout << "Running time: " << x.time << endl;
		}
		if (strcmp(argv[4], "-comp") == 0)
		{
			std::cout << "Comparisions: " << x.cmpNum << endl;
		}
		if (strcmp(argv[4], "-both") == 0)
		{
			std::cout << "Running time: " << x.time << endl;
			std::cout << "Comparisions: " << x.cmpNum << endl;
		}
		std::cout << endl;
	}

	delete[] a;
}

// COMMAND PROMPT 4
void command_4(int argc, const char *argv[])
{
	// declare variables
	int *n, *m;
	int size;
	result a, b;

	getDataFromFile(argv[4], n, size);
	m = new int[size];

	// process
	for (int j = 0; j < size; j++)
		m[j] = n[j];

	algorithm(n, size, argv[2], "-both", a);
	algorithm(m, size, argv[3], "-both", b);

	// print
	std::cout << "COMPARE MODE" << endl;
	std::cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
	std::cout << "Input file: " << argv[4] << endl;
	std::cout << "Input size: " << size << endl;
	std::cout << "--------------------------------------------" << endl;
	std::cout << "Running time: " << a.time << " | " << b.time << endl;
	std::cout << "Comparision: " << a.cmpNum << " | " << b.cmpNum << endl;

	delete[] n;
	delete[] m;
}

// COMMAND PROMPT 5
void command_5(int argc, const char *argv[])
{
	// declare variables
	int size = atoi(argv[4]);
	int *n = new int[size];
	int *m = new int[size];
	result a, b;
	const char *order_temp[] = {"-rand", "-nsorted", "-sorted", "-rev"};
	const char *order[] = {"Randomized", "Nearly Sorted", "Sorted", "Reversed"};

	// print
	std::cout << "COMPARE MODE" << endl;
	std::cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
	std::cout << "Input size: " << size << endl;

	int i;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(argv[5], order_temp[i]) == 0)
		{
			GenerateData(n, size, i);
			for (int j = 0; j < size; j++)
				m[j] = n[j];
			break;
		}
	}

	writeDataToFile("input.txt", n, size);
	algorithm(n, size, argv[2], "-both", a);
	algorithm(m, size, argv[3], "-both", b);

	// print
	std::cout << "Input order: " << order[i] << endl;
	std::cout << "--------------------------------------------" << endl;
	std::cout << "Running time: " << a.time << " | " << b.time << endl;
	std::cout << "Comparision: " << a.cmpNum << " | " << b.cmpNum << endl;

	delete[] n;
	delete[] m;
}

// function to indicate which function amongst 5 processing functions will be executed and hence execute it
void executeSpecificFunction(int argc, const char *argv[])
{
	if (strcmp(argv[1], "-a") == 0)
	{
		if (argc == 5)
		{
			const char *p;
			p = strchr(argv[3], '.');
			if (p != nullptr && strcmp(p, ".txt") == 0)
			{
				command_1(argc, argv);
				return;
			}
			else
			{
				command_3(argc, argv);
				return;
			}
		}
		else if (argc == 6)
		{
			command_2(argc, argv);
			return;
		}
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 5)
		{
			command_4(argc, argv);
			return;
		}
		else if (argc == 6)
		{
			command_5(argc, argv);
			return;
		}
	}
	cout << "Invalid input. Please check out the command lines below and try again." << endl;
	cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]" << endl;
	cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]" << endl;
	cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]" << endl;
	cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
	cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]";
}