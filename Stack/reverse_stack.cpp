// GFG - Reverse a Stack

class Solution {
  public:
  
    void insertAtBottom(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int num = st.top();
        st.pop();
        
        insertAtBottom(st, x);
        
        st.push(num);
    }
  
    void reverseStack(stack<int> &st) {
        if( st.empty()){
            return;
        }
        
        int num = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st,num);
        
    }
};