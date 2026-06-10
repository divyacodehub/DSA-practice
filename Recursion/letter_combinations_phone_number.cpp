#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {

    // Base case
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++) {

        output.push_back(value[i]);

        solve(digits, output, index + 1, ans, mapping);

        // Backtrack
        output.pop_back();
    }
}

int main() {

    string digits = "23";

    string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> ans;
    string output = "";

    solve(digits, output, 0, ans, mapping);

    for(string s : ans)
        cout << s << " ";

    return 0;
}