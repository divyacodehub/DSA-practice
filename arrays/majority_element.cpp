// LeetCode 169 - Majority Element
// Approach 1: Hash Map
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];

            if(count == 0)
            candidate = num;

            if(candidate == num){
                count++;
            }
            else
            count --;
        }
        return candidate;
    }
};