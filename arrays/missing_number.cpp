// LeetCode 268 - Missing Number
// Approach 1: Sum Formula
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

            int expected_sum = n * (n+1) / 2;
            int actual_sum = 0;

            for(int i = 0; i < n; i++){
            int num = nums[i];

            actual_sum +=num;

        }
        return expected_sum - actual_sum;
    }
};


// Approach 2: XOR

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
    }
};