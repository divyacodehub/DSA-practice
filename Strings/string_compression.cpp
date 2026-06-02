#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<char> chars = {'a','a','b','b','c','c','c'};

    vector<char> ans;

    int i = 0;

    while(i < chars.size()) {

        char curr = chars[i];
        int count = 0;

        while(i < chars.size() && chars[i] == curr) {
            count++;
            i++;
        }

        ans.push_back(curr);

        if(count > 1) {

            string str = to_string(count);

            for(char ch : str)
                ans.push_back(ch);
        }
    }

    for(char ch : ans)
        cout << ch;

    return 0;
}