// LeetCode 238 - Product of Array Except Self
// Approach 2: Prefix Product + Suffix Product
// Time: O(n)
// Space: O(1) (excluding output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int leftprod = 1;
        for(int i = 0; i < n; i++){
            ans[i] = leftprod;
            leftprod *= nums[i];
        }
        int rightprod = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= rightprod;
            rightprod *= nums[i];
        }
        return ans;
    }
};