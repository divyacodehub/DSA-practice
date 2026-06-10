#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key) {

    if(start > end)
        return false;

    int mid = start + (end - start) / 2;

    if(arr[mid] == key)
        return true;

    if(arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);

    return binarySearch(arr, start, mid - 1, key);
}

int main() {

    int arr[] = {1,2,3,4,5,6,7};
    int key = 6;

    cout << binarySearch(arr, 0, 6, key);

    return 0;
}