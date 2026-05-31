#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 7};
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int x : arr) {
        if (x > maxi) maxi = x;
        if (x < mini) mini = x;
    }
    cout << "Max: " << maxi << endl;
    cout << "Min: " << mini << endl;
    return 0;
}