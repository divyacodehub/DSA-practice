// LeetCode 394 - Decode String

class Solution {
public:
    string decodeString(string s) {

    // Stack to store numbers 
    stack<int> numStack;

    // Stack to store previous strings
    stack<string> strStack;

    int num = 0;          // Current number being formed
    string curr = "";     // Current string being formed

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // CASE 1: Digit
            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

         // CASE 2: Opening bracket
        else if(ch == '[') {

            // Save current state
            numStack.push(num);
             strStack.push(curr);

             // Reset for inner bracket
             num = 0;
             curr = "";
            }

            // CASE 3: Letter
         else if(isalpha(ch)) {
            curr += ch;
            }

        // CASE 4: Closing bracket
        else if(ch == ']') {

            // Get repeat count
            int repeat = numStack.top();
            numStack.pop();

            // Get previous string
            string prev = strStack.top();
            strStack.pop();

            // Repeat current string
            string temp = "";

            for(int j = 0; j < repeat; j++) {
                 temp += curr;
                }

            // Attach to previous string
            curr = prev + temp;
            }
        }

        return curr;
    }
};