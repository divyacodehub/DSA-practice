#include <iostream>
#include <string>
using namespace std;

int main() {

    string s = "my name is divya";

    string temp = "";

    for(char ch : s) {

        if(ch == ' ')
            temp += "@40";
        else
            temp += ch;
    }

    cout << temp;

    return 0;
}