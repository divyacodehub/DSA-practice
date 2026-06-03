#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key) {

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int getPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start < end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    int arr[] = {7,9,1,2,3};
    int n = 5;
    int key = 2;

    int pivot = getPivot(arr, n);

    if(key >= arr[pivot] && key <= arr[n - 1])
        cout << binarySearch(arr, pivot, n - 1, key);
    else
        cout << binarySearch(arr, 0, pivot - 1, key);

    return 0;
}