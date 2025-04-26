#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Swap utility
void swap(long int &a, long int &b)
{
    long int tmp = a;
    a = b;
    b = tmp;
}

// Bubble sort
void bubbleSort(vector<long int> &arr)
{
    long int n = arr.size();
    for (long int i = 0; i < n - 1; i++)
    {
        for (long int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Partition function for Quick Sort
long int partition(vector<long int> &a, long int m, long int p)
{
    int v,i,j;
    v=a[m];
    i=m;
    j=p;
    while(i<j)
    {
        while(i<p && a[i]<=v)
            i=i+1;
        while(j>m && a[j]>=v)
            j=j-1;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[m], a[j]);
    return j;
}

// Quick sort
void quickSort(vector<long int> &arr, long int low, long int high)
{
    if (low < high)
    {
        long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    long int n = 10000;
    int it = 0;

    cout << "A_size, Bubble, Quick\n";

    while (it < 10)
    {
        vector<long int> a(n), b(n);

        for (long int i = 0; i < n; i++)
        {
            long int num = rand() % n + 1;
            a[i] = b[i] = num;
        }

        clock_t start, end;

        // Bubble Sort timing
        start = clock();
        bubbleSort(a);
        end = clock();
        double bubbleTime = double(end - start);

        // Quick Sort timing
        start = clock();
        quickSort(b, 0, n - 1);
        end = clock();
        double quickTime = double(end - start);

        // Output
        cout << n << ", "
             << (long int)bubbleTime << ", "
             << (long int)quickTime << "\n";

        n += 10000;
        it++;
    }
    return 0;
}