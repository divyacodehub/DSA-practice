#include <iostream>
#include <string>
using namespace std;

int main() {

    string s = "abbaca";

    string ans = "";

    for(char ch : s) {

        if(!ans.empty() && ans.back() == ch)
            ans.pop_back();
        else
            ans.push_back(ch);
    }

    cout << ans;

    return 0;
}