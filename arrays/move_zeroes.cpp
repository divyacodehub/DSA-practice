#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    int j = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}