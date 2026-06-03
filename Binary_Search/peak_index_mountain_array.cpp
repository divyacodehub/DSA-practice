#include <iostream>
using namespace std;

int peakIndex(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start < end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] < arr[mid + 1])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    int arr[] = {0,2,4,7,5,3,1};
    int n = 7;

    cout << peakIndex(arr, n);
    return 0;
}