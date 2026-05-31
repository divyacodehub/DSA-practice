#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    return 0;
}