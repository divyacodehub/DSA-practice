#include <iostream>
using namespace std;

void merge(int arr[], int start, int end) {

    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainIndex = start;

    for(int i = 0; i < len1; i++)
        first[i] = arr[mainIndex++];

    mainIndex = mid + 1;

    for(int i = 0; i < len2; i++)
        second[i] = arr[mainIndex++];

    int index1 = 0;
    int index2 = 0;

    mainIndex = start;

    while(index1 < len1 && index2 < len2) {

        if(first[index1] < second[index2])
            arr[mainIndex++] = first[index1++];
        else
            arr[mainIndex++] = second[index2++];
    }

    while(index1 < len1)
        arr[mainIndex++] = first[index1++];

    while(index2 < len2)
        arr[mainIndex++] = second[index2++];

    delete[] first;
    delete[] second;
}

// Merge Sort
void mergeSort(int arr[], int start, int end) {

    // Base case
    if(start >= end)
        return;

    int mid = start + (end - start) / 2;

    // Sort left half
    mergeSort(arr, start, mid);

    // Sort right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, end);
}

int main() {

    int arr[] = {38, 27, 43, 3, 9, 82, 89};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}