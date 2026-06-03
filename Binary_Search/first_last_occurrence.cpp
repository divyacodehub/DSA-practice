#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1,2,3,3,3,3,4,5};
    int n = 8;
    int key = 3;

    cout << "First: " << firstOccurrence(arr,n,key) << endl;
    cout << "Last: " << lastOccurrence(arr,n,key);

    return 0;
}