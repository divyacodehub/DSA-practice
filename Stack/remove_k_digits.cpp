// LeetCode 402 - Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for (int i = 0; i < n; i++ ) {

            while((!st.empty()) && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        //if k still remains , remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        //build ans from stack
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        //reverse because stack gives reverse order
        reverse(ans.begin(),ans.end());

        //remove leading zeroes
        int i = 0;
        while( i < ans.size() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);

        //edge case-empty string
        if(ans == ""){
            return "0";
        }

        return ans;
    }
};