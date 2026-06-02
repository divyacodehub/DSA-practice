#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {

    string temp = "";

    for(char ch : s) {
        if(isalnum(ch))
            temp += tolower(ch);
    }

    int start = 0;
    int end = temp.length() - 1;

    while(start < end) {

        if(temp[start] != temp[end])
            return false;

        start++;
        end--;
    }

    return true;
}

int main() {

    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome(s))
        cout << "Valid Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}