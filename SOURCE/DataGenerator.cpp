#include "Header.h"

////Generate Data
void swap(int &a1, int &a2)
{
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        swap(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0: // ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1: // gần như có thứ tự
        GenerateNearlySortedData(a, n);
        break;
    case 2: // có thứ tự
        GenerateSortedData(a, n);
        break;
    case 3: // có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}