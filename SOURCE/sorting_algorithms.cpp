#include "Header.h"

// --------------------------------Utility functions-----------------------------------------
// utilities for Heap Sort
void sift_Comparison(int *a, int left, int right, unsigned long long &cmpCounter)
{
    int i = left, j = 2 * i + 1;
    int x = a[i];
    while (++cmpCounter && j <= right)
    {
        if (++cmpCounter && j < right)
            if (++cmpCounter && a[j] < a[j + 1])
                j++;
        if (++cmpCounter && x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void constructHeap_Comparison(int *a, int left, int right, unsigned long long &cmpCounter)
{
    int mid = right / 2;
    while (++cmpCounter && mid >= 0)
    {
        sift_Comparison(a, mid, right, cmpCounter);
        mid--;
    }
}

void sift_RunningTime(int *a, int left, int right)
{
    int i = left, j = 2 * i + 1;
    int x = a[i];
    while (j <= right)
    {
        if (j < right)
            if (a[j] < a[j + 1])
                j++;
        if (x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void constructHeap_RunningTime(int *a, int left, int right)
{
    int mid = right / 2;
    while (mid >= 0)
    {
        sift_RunningTime(a, mid, right);
        mid--;
    }
}

// utilities for Merge Sort
void merge_Comparison(int *a, int left, int mid, int right, unsigned long long &cmpCounter)
{
    // create 2 subarrays
    int n1 = mid - left + 1, n2 = right - mid;
    int *a1 = new int[n1], *a2 = new int[n2];
    for (int i = 0; ++cmpCounter && i < n1; i++)
        a1[i] = a[left + i];
    for (int i = 0; ++cmpCounter && i < n2; i++)
        a2[i] = a[mid + 1 + i];

    int idx1 = 0, idx2 = 0; // 2 variables to keep track of index in the subarrays
    int idx = left;         // 1 variable to keep track of index in the big array

    // merging process
    while (++cmpCounter && idx1 < n1 && ++cmpCounter && idx2 < n2)
    {
        (++cmpCounter && (a1[idx1] < a2[idx2])) ? a[idx++] = a1[idx1++] : a[idx++] = a2[idx2++];
    }
    while (++cmpCounter && idx1 < n1)
        a[idx++] = a1[idx1++];
    while (++cmpCounter && idx2 < n2)
        a[idx++] = a2[idx2++];

    delete[] a1;
    delete[] a2;
}

void MergeSort_Comparison_Inner(int *a, int left, int right, unsigned long long &cmpCounter)
{
    if (++cmpCounter && left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort_Comparison_Inner(a, left, mid, cmpCounter);
    MergeSort_Comparison_Inner(a, mid + 1, right, cmpCounter);

    merge_Comparison(a, left, mid, right, cmpCounter);
}

void merge_RunningTime(int *a, int left, int mid, int right)
{
    // create 2 subarrays
    int n1 = mid - left + 1, n2 = right - mid;
    int *a1 = new int[n1], *a2 = new int[n2];
    for (int i = 0; i < n1; i++)
        a1[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        a2[i] = a[mid + 1 + i];

    int idx1 = 0, idx2 = 0; // 2 variables to keep track of index in the subarrays
    int idx = left;         // 1 variable to keep track of index in the big array

    // merging process
    while (idx1 < n1 && idx2 < n2)
        (a1[idx1] < a2[idx2]) ? a[idx++] = a1[idx1++] : a[idx++] = a2[idx2++];
    while (idx1 < n1)
        a[idx++] = a1[idx1++];
    while (idx2 < n2)
        a[idx++] = a2[idx2++];

    delete[] a1;
    delete[] a2;
}

void MergeSort_RunningTime_Inner(int *a, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort_RunningTime_Inner(a, left, mid);
    MergeSort_RunningTime_Inner(a, mid + 1, right);

    merge_RunningTime(a, left, mid, right);
}

// utilities for Quick Sort
int Partition_Comparison(int *a, int left, int right, unsigned long long &cmpCounter)
{
    int pivotIdx = (left + right) / 2;
    int p = a[pivotIdx];
    int i = left, j = right;
    while (++cmpCounter && i <= j)
    {
        while (++cmpCounter && a[i] < p)
            i++;
        while (++cmpCounter && a[j] > p)
            j--;
        if (++cmpCounter && i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;
}

void QuickSort_Comparison_Inner(int *a, int left, int right, unsigned long long &cmpCounter)
{
    int s = Partition_Comparison(a, left, right, cmpCounter);
    if (++cmpCounter && left < s - 1)
        QuickSort_Comparison_Inner(a, left, s - 1, cmpCounter);
    if (++cmpCounter && right > s)
        QuickSort_Comparison_Inner(a, s, right, cmpCounter);
}

int Partition_RunningTime(int *a, int left, int right)
{
    int pivotIdx = (left + right) / 2;
    int p = a[pivotIdx];
    int i = left, j = right;
    while (i <= j)
    {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;
}

void QuickSort_RunningTime_Inner(int *a, int left, int right)
{
    int s = Partition_RunningTime(a, left, right);
    if (left < s - 1)
        QuickSort_RunningTime_Inner(a, left, s - 1);
    if (right > s)
        QuickSort_RunningTime_Inner(a, s, right);
}

// utilities for Radix Sort
int getNumOfDigits_Comparison(int *a, int n, unsigned long long &cmpCounter)
{
    int max = a[0];
    for (int i = 1; ++cmpCounter && i < n; i++)
        if (++cmpCounter && a[i] > max)
            max = a[i];

    int numOfDigits = 0;
    while (++cmpCounter && max != 0)
    {
        max /= 10;
        numOfDigits++;
    }

    return numOfDigits;
}

int getNumOfDigits_RunningTime(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int numOfDigits = 0;
    while (max != 0)
    {
        max /= 10;
        numOfDigits++;
    }

    return numOfDigits;
}

void CountingSort_Decimal_Comparison(int *a, int n, int k, unsigned long long &cmpCounter)
{
    int *f = new int[10]{0}; // array to store occurences
    int *b = new int[n];     //  array to temporarily store values

    for (int i = 0; ++cmpCounter && i < n; i++)
        f[(a[i] / k) % 10]++;
    for (int i = 1; ++cmpCounter && i < 10; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; ++cmpCounter && i >= 0; i--)
    {
        b[f[(a[i] / k) % 10] - 1] = a[i];
        f[(a[i] / k) % 10]--;
    }

    for (int i = 0; ++cmpCounter && i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] f;
}

void CountingSort_Decimal_RunningTime(int *a, int n, int k)
{
    int *f = new int[10]{0}; // array to store occurences
    int *b = new int[n];     //  array to temporarily store values

    for (int i = 0; i < n; i++)
        f[(a[i] / k) % 10]++;
    for (int i = 1; i < 10; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        b[f[(a[i] / k) % 10] - 1] = a[i];
        f[(a[i] / k) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] f;
}
//------------------------------------------------------------------------------------------

//------------------------------------Sorting functions-------------------------------------
// Selection Sort
unsigned long long SelectionSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    // sorting process
    for (int i = 0; ++cmpCounter && i < n - 1; i++)
    {
        int minVal = a[i];
        int minIndex = i;
        for (int j = i + 1; ++cmpCounter && j < n; j++)
        {
            if (++cmpCounter && a[j] < minVal)
            {
                minVal = a[j];
                minIndex = j;
            }
        }
        a[minIndex] = a[i];
        a[i] = minVal;
    }

    return cmpCounter;
}

double SelectionSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    for (int i = 0; i < n - 1; i++)
    {
        int minVal = a[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < minVal)
            {
                minVal = a[j];
                minIndex = j;
            }
        }
        a[minIndex] = a[i];
        a[i] = minVal;
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Insertion Sort
unsigned long long InsertionSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    // sorting process
    for (int i = 1; ++cmpCounter && i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (++cmpCounter && j >= 0 && ++cmpCounter && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }

    return cmpCounter;
}

double InsertionSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Bubble Sort
unsigned long long BubbleSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    // sorting process
    for (int i = 1; ++cmpCounter && i < n; i++)
    {
        for (int j = n - 1; ++cmpCounter && j >= i; j--)
        {
            if (++cmpCounter && a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
        }
    }

    return cmpCounter;
}

double BubbleSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
        }
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Heap Sort
unsigned long long HeapSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    // sorting process
    int right = n - 1;
    constructHeap_Comparison(a, 0, right, cmpCounter);
    while (++cmpCounter && right > 0)
    {
        swap(a[right], a[0]);
        right--;
        sift_Comparison(a, 0, right, cmpCounter);
    }

    return cmpCounter;
}

double HeapSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    int right = n - 1;
    constructHeap_RunningTime(a, 0, right);
    while (right > 0)
    {
        swap(a[right], a[0]);
        right--;
        sift_RunningTime(a, 0, right);
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Merge Sort
unsigned long long MergeSort_Comparison(int *a, int n)
{
    int left = 0, right = n - 1;
    unsigned long long cmpCounter = 0;

    MergeSort_Comparison_Inner(a, left, right, cmpCounter);

    return cmpCounter;
}

double MergeSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    MergeSort_RunningTime_Inner(a, 0, n - 1);

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Quick Sort
unsigned long long QuickSort_Comparison(int *a, int n)
{
    int left = 0, right = n - 1;
    unsigned long long cmpCounter = 0;

    // sorting process
    QuickSort_Comparison_Inner(a, left, right, cmpCounter);

    return cmpCounter;
}

double QuickSort_RunningTime(int *a, int n)
{
    int left = 0, right = n - 1;

    clock_t start, end;
    start = clock();

    // sorting process
    QuickSort_RunningTime_Inner(a, left, right);

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Radix Sort
unsigned long long RadixSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;
    int k = getNumOfDigits_Comparison(a, n, cmpCounter);
    for (int i = 1, exponent = 1; ++cmpCounter && i <= k; i++, exponent *= 10)
        CountingSort_Decimal_Comparison(a, n, exponent, cmpCounter);

    return cmpCounter;
}

double RadixSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    int k = getNumOfDigits_RunningTime(a, n);
    for (int i = 1, exponent = 1; i <= k; i++, exponent *= 10)
        CountingSort_Decimal_RunningTime(a, n, exponent);

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Shaker Sort
unsigned long long ShakerSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int i = right; ++cmpCounter && i >= left; i--)
        {
            if (++cmpCounter && a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
            }
        }
        left = k + 1;
        for (int i = left; ++cmpCounter && i <= right; i++)
        {
            if (++cmpCounter && a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
            }
        }
        right = k - 1;
    } while (++cmpCounter && left <= right);

    return cmpCounter;
}

double ShakerSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    int left = 1, right = n - 1, k = n - 1;
    do
    {
        for (int i = right; i >= left; i--)
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
            }
        left = k + 1;
        for (int i = left; i <= right; i++)
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                k = i;
            }
        right = k - 1;
    } while (left <= right);

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Shell Sort
unsigned long long ShellSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    for (int gap = n / 2; ++cmpCounter && gap > 0; gap /= 2)
    {
        for (int i = gap; ++cmpCounter && i < n; i++)
        {
            int temp = a[i];
            int j;

            for (j = i; ++cmpCounter && j >= gap && ++cmpCounter && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }

            a[j] = temp;
        }
    }

    return cmpCounter;
}

double ShellSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;

            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }

            a[j] = temp;
        }
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Counting Sort
unsigned long long CountingSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;
    int *f = new int[n]{0};
    int *b = new int[n];

    for (int i = 0; ++cmpCounter && i < n; i++)
        f[a[i]]++;
    for (int i = 1; ++cmpCounter && i < n; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; ++cmpCounter && i >= 0; i--)
    {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }

    for (int i = 0; ++cmpCounter && i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] f;

    return cmpCounter;
}

double CountingSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    int *f = new int[n]{0};
    int *b = new int[n];

    for (int i = 0; i < n; i++)
        f[a[i]]++;
    for (int i = 1; i < n; i++)
        f[i] += f[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
    delete[] f;

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}

// Flash Sort
unsigned long long FlashSort_Comparison(int *a, int n)
{
    unsigned long long cmpCounter = 0;

    // sorting process
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m]{0};

    for (int i = 1; ++cmpCounter && i < n; i++)
    {
        if (++cmpCounter && a[i] < minVal)
            minVal = a[i];
        if (++cmpCounter && a[i] > a[max])
            max = i;
    }

    double c1 = (double)(m - 1) / (a[max] - minVal);

    for (int i = 0; ++cmpCounter && i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; ++cmpCounter && i < m; i++)
        l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++cmpCounter && nmove < n - 1)
    {
        while (++cmpCounter && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++cmpCounter && k < 0)
            break;
        while (++cmpCounter && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            --l[k];
            swap(flash, a[l[k]]);
            ++nmove;
        }
    }
    delete[] l;

    // Insertion sort
    for (int i = 1; ++cmpCounter && i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (++cmpCounter && j >= 0 && ++cmpCounter && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }

    return cmpCounter;
}

double FlashSort_RunningTime(int *a, int n)
{
    clock_t start, end;
    start = clock();

    // sorting process
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m]{0};

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }

    double c1 = (double)(m - 1) / (a[max] - minVal);

    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            --l[k];
            swap(flash, a[l[k]]);
            ++nmove;
        }
    }
    delete[] l;

    // Insertion sort
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }

    end = clock();
    double time = double(end - start) / double(CLOCKS_PER_SEC);

    return time * (double)1000;
}