// GFG - The Celebrity Problem

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> st;
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1) {
            
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(mat[a][b] == 1){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int candidate = st.top();
        
        for(int i = 0; i < n; i++) {
            if(i != candidate && mat[i][candidate] == 0 ) {
            return -1;
            }
            
            if(i != candidate && mat[candidate][i] == 1 ) {
            return -1; 
            }
        }    
            return candidate;
            
    }
};