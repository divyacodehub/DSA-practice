#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << "Found at index: " << i;
            return 0;
        }
    }
    cout << "Not found";
    return 0;
}