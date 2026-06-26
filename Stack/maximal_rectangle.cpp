// LeetCode 85 - Maximal Rectangle

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>heights(m,0);
        int ans =0;

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++ ) {

                if(matrix[i][j] == '1') 
                heights[j]++;

                else
                heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        } 
        return ans; 
    }
};