// #pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;

struct result
{
    unsigned long long cmpNum;
    double time;
};

//----------SORTING FUNCTIONS----------
// Selection Sort
unsigned long long SelectionSort_Comparison(int *a, int n);
double SelectionSort_RunningTime(int *a, int n);

// Insertion Sort
unsigned long long InsertionSort_Comparison(int *a, int n);
double InsertionSort_RunningTime(int *a, int n);

// Bubble Sort
unsigned long long BubbleSort_Comparison(int *a, int n);
double BubbleSort_RunningTime(int *a, int n);

// utilities for Heap Sort
void sift_Comparison(int *a, int left, int right, unsigned long long &cmpCounter);
void constructHeap_Comparison(int *a, int left, int right, unsigned long long &cmpCounter);
void sift_RunningTime(int *a, int left, int right);
void constructHeap_RunningTime(int *a, int left, int right);
// Heap Sort
unsigned long long HeapSort_Comparison(int *a, int n);
double HeapSort_RunningTime(int *a, int n);

// utilities for Merge Sort
void merge_Comparison(int *a, int left, int mid, int right, unsigned long long &cmpCounter);
void MergeSort_Comparison_Inner(int *a, int left, int right, unsigned long long &cmpCounter);
void merge_RunningTime(int *a, int left, int mid, int right);
void MergeSort_RunningTime_Inner(int *a, int left, int right);
// Merge Sort
unsigned long long MergeSort_Comparison(int *a, int n);
double MergeSort_RunningTime(int *a, int n);

// utilities for Quick Sort
int Partition_Comparison(int *a, int left, int right, unsigned long long &cmpCounter);
void QuickSort_Comparison_Inner(int *a, int left, int right, unsigned long long &cmpCounter);
int Partition_RunningTime(int *a, int left, int right);
void QuickSort_RunningTime_Inner(int *a, int left, int right);
// Quick Sort
unsigned long long QuickSort_Comparison(int *a, int n);
double QuickSort_RunningTime(int *a, int n);

// utilities for Radix Sort
int getNumOfDigits_Comparison(int *a, int n, unsigned long long &cmpCounter);
int getNumOfDigits_RunningTime(int *a, int n);
void CountingSort_Decimal_Comparison(int *a, int n, int k, unsigned long long &cmpCounter);
void CountingSort_Decimal_RunningTime(int *a, int n, int k);
// Radix Sort
unsigned long long RadixSort_Comparison(int *a, int n);
double RadixSort_RunningTime(int *a, int n);

// Shaker Sort
unsigned long long ShakerSort_Comparison(int *a, int n);
double ShakerSort_RunningTime(int *a, int n);

// Shell Sort
unsigned long long ShellSort_Comparison(int *a, int n);
double ShellSort_RunningTime(int *a, int n);

// Counting Sort
unsigned long long CountingSort_Comparison(int *a, int n);
double CountingSort_RunningTime(int *a, int n);

// Flash Sort
unsigned long long FlashSort_Comparison(int *a, int n);
double FlashSort_RunningTime(int *a, int n);
//----------------------------------------

// functions with particular tasks for 5 command functions
void algorithm(int *a, int n, const char *name, const char *param, result &x);
void getDataFromFile(const char *file, int *&a, int &n);
void writeDataToFile(const char *file, int *a, int n);

//----------COMMAND LINE FUNCTIONS----------
void command_1(int argc, const char *argv[]);
void command_2(int argc, const char *argv[]);
void command_3(int argc, const char *argv[]);
void command_4(int argc, const char *argv[]);
void command_5(int argc, const char *argv[]);
//----------------------------------------

// function to execute 5 command line functions
void executeSpecificFunction(int argc, const char *argv[]);

//----------Generate Data----------
void swap(int &a1, int &a2);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);