//Shaker Sort is a variation of the bubble sort which make both the extreme value (smallest and largest) of the remainning un sorted array float to its correct posision (2 end of the array)

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
    T x = a;
    a = b;
    b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
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
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0:	// ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1:	// có thứ tự
        GenerateSortedData(a, n);
        break;
    case 2:	// có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    case 3:	// gần như có thứ tự
        GenerateNearlySortedData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}

int* DuplicateArray(int*& arr, int n) {
    int* dupArray = new int[n];

    for (int i = 0; i < n; i++) {
        dupArray[i] = arr[i];
    }
    return dupArray;
}


void ShakerSort(int*& arr, int n) {
    
    int left = 0;
    int right = n - 1;
    int lastSwapPos = n - 2;
    bool stillSwaping = true;

    while (stillSwaping) {
        stillSwaping = false;
            
        //
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                HoanVi(arr[i], arr[i + 1]);
                lastSwapPos = i;
                stillSwaping = true;
            }
        }

        //
        if (!stillSwaping)
        {
            break;
        }

        //
        stillSwaping = false;
        right = lastSwapPos;
        //
        for (int j = right; j > left; j--) {
            if (arr[j - 1] > arr[j]) {
                HoanVi(arr[j], arr[j - 1]);
                lastSwapPos = j;
                stillSwaping = true;
            }   
        }
        left = lastSwapPos;
    }
}

void SelectionSort(int*& arr, int n) {

    int minPos;

    for (int i = 0; i < n - 1; i++) {
        minPos = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[minPos] > arr[j]) {
                minPos =j;
            }
        }
        if (minPos != i) {
            HoanVi(arr[i], arr[minPos]);
        }
    }
}
//Tham khao tren : "https://www.geeksforgeeks.org/heap-sort/"
void Heapify(int*& arr, int n, int rootPos) {

    int max = rootPos;
    int leftChildPos = rootPos * 2 + 1;
    int rightChildPos = rootPos * 2 + 2;

    if (leftChildPos < n && arr[leftChildPos] > arr[max]) {
        max = leftChildPos;
    }

    if (rightChildPos < n && arr[rightChildPos] > arr[max]) {
        max = rightChildPos;
    }

    if (max != rootPos) {
        HoanVi(arr[rootPos], arr[max]);
        Heapify(arr, n, max);
    }
}

void HeapSort(int*& arr, int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        HoanVi(arr[0], arr[i]);

        Heapify(arr, i, 0);
    }

}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int n = 100;
    int* a = NULL;
    GenerateData(a, n, 0);
    int* b = DuplicateArray(a, n);
    double seconds;
    time_t begin;
    time_t end;

    time(&begin);

    HeapSort(b, 9);
    
    time(&end);

    seconds = difftime(begin, end);
    cout << 1000.0 * seconds << endl;
    printArray(b, 9);

    cout << endl;
    cout << "Hello World!\n";

}
