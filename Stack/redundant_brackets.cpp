// GFG - Expression Contains Redundant Brackets or Not

class Solution {
  public:
    bool checkRedundancy(string &s) {
      
      stack<char> st;
      
      for(int i = 0; i < s.length(); i++){
          char ch = s[i];
          
          if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*' ){
              st.push(ch);
          }
          
          else if(ch == ')') {
              
              bool isredundant = true;
              
              while(!st.empty() && st.top() != '(') {
                  
                  char top = st.top();
                  
                  if( top == '+' || top == '-' || top == '/' || top == '*' ){
                      
                      isredundant = false; 
                  }  
                      st.pop();
              }
              
              st.pop();
              
              if(isredundant == true){
                  return true;
              }
          }
      }
      return false;
        
    }
};

