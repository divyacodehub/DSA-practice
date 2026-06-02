#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26], int b[26]) {

    for(int i = 0; i < 26; i++) {
        if(a[i] != b[i])
            return false;
    }

    return true;
}

int main() {

    string s1 = "ab";
    string s2 = "eidbaooo";

    int count1[26] = {0};

    for(char ch : s1) {
        count1[ch - 'a']++;
    }

    int windowSize = s1.length();

    int count2[26] = {0};

    for(int i = 0; i < windowSize; i++) {
        count2[s2[i] - 'a']++;
    }

    if(checkEqual(count1, count2)) {
        cout << "True";
        return 0;
    }

    int i = windowSize;

    while(i < s2.length()) {

        count2[s2[i] - 'a']++;

        count2[s2[i - windowSize] - 'a']--;

        if(checkEqual(count1, count2)) {
            cout << "True";
            return 0;
        }

        i++;
    }

    cout << "False";

    return 0;
}