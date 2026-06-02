#include <iostream>
#include <string>
using namespace std;

int main() {

    string s = "testsample";

    int count[26] = {0};

    for(char ch : s) {
        count[ch - 'a']++;
    }

    int maxi = -1;
    char ans;

    for(int i = 0; i < 26; i++) {

        if(count[i] > maxi) {
            maxi = count[i];
            ans = 'a' + i;
        }
    }

    cout << ans;

    return 0;
}