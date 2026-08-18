// GFG - First Negative Integer in Every Window
// Approach: Queue + Sliding Window
// Time: O(n)
// Space: O(k)


class Solution {
public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        
        vector<int> ans;
        deque<int> dq;

        // Process first window
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }

        // Process remaining windows
        for (int i = k; i < arr.size(); i++) {

            // Store first negative of previous window
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            }
            else {
                ans.push_back(0);
            }

            // Remove elements that are out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Add current element if it is negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }

        // Answer for the last window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        }
        else {
            ans.push_back(0);
        }

        return ans;
    }
};