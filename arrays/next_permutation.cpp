// LeetCode 31 - Next Permutation
// Approach: Pivot + Swap + Reverse
// Time: O(n)
// Space: O(1)


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        //find pivot
        int pivot = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }
        
        //find next freater element than pivot from right side
        if(pivot != -1){
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
    }

        //reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};