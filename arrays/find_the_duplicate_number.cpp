// LeetCode 287 - Find the Duplicate Number
// Approach: Floyd's Cycle Detection
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Find the meeting point
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }   while(slow != fast);

            // Find the entrance of the cycle
            slow = nums[0];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
        return slow;
    }
};