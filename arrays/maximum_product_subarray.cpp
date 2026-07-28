// LeetCode 152 - Maximum Product Subarray
// Approach: Dynamic Programming
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int minprod = nums[0]; 
       int maxprod = nums[0];
       int ans = nums[0];

       for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maxprod,minprod);
            }

            maxprod = max(nums[i],maxprod * nums[i]);
            minprod = min(nums[i],minprod * nums[i]);

            ans = max(ans,maxprod);
       }
       return ans;
    }
};