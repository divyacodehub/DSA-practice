#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, vector<int> output, int index) {

    // Base case
    if(index >= nums.size()) {

        for(int i : output)
            cout << i << " ";

        cout << endl;
        return;
    }

    // Exclude current element
    solve(nums, output, index + 1);

    // Include current element
    output.push_back(nums[index]);

    solve(nums, output, index + 1);
}

int main() {

    vector<int> nums = {1, 2, 3};

    vector<int> output;

    solve(nums, output, 0);

    return 0;
}