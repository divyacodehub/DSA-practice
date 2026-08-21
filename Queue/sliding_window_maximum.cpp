// LeetCode 239 - Sliding Window Maximum
// Approach: Monotonic Deque
// Time: O(n)
// Space: O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;  // Stores maximum of each window
        deque<int> dq;    // Stores indices of useful elements

        for(int i = 0; i < nums.size(); i++){

             // 1. Remove elements that are outside the current window
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // 2. Remove smaller elements from the back
            // They can never become the maximum because nums[i] is bigger
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // 3. Add the current element's index
            dq.push_back(i);

            // 4. Once we have a complete window, store its maximum
            // The front of deque always contains the maximum element's index
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
       return ans;
    }
};