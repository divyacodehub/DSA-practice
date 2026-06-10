#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, int index) {

    // Base case
    if(index >= nums.size()) {

        for(int i : nums)
            cout << i << " ";

        cout << endl;
        return;
    }

    for(int j = index; j < nums.size(); j++) {

        // Place element at current position
        swap(nums[index], nums[j]);

        // Recursive call
        solve(nums, index + 1);

        // Backtrack
        swap(nums[index], nums[j]);
    }
}

int main() {

    vector<int> nums = {1, 2, 3};

    solve(nums, 0);

    return 0;
}