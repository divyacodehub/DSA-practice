// LeetCode 84 - Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

       stack<int> st;
       int n = heights.size();
       int maxArea = 0;

       for(int i = 0; i <= n; i++){

        while((!st.empty()) && (i == n || heights[st.top()] >= heights[i]) ) {

            int height = heights[st.top()];
            st.pop();

            int right = i;

            int left;
            if(st.empty())
            left = -1;
            else
            left = st.top();

            int width = right - left - 1;

            maxArea = max(maxArea,height *width);
        }
        st.push(i);
       }
       return maxArea;
    }
};