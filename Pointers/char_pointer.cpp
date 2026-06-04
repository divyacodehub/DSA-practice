#include <iostream>
using namespace std;

int main() {
    char ch = 'A';

    char *ptr = &ch;

    cout << ch << endl;
    cout << ptr << endl;

    return 0;
}