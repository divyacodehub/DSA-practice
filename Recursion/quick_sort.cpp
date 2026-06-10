#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {

    int pivot = arr[start];

    int count = 0;

    for(int i = start + 1; i <= end; i++) {
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

// Quick Sort
void quickSort(int arr[], int start, int end) {

    // Base case
    if(start >= end)
        return;

    int p = partition(arr, start, end);

    // Sort left part
    quickSort(arr, start, p - 1);

    // Sort right part
    quickSort(arr, p + 1, end);
}

int main() {

    int arr[] = {5, 3, 7, 1, 9, 2};
    int n = 6;

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}