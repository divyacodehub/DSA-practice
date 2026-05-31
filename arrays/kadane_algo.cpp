#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int sum = 0;
    int maxi = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }
    cout << "Max Subarray Sum: " << maxi;
    return 0;
}