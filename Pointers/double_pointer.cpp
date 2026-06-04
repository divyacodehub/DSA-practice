#include <iostream>
using namespace std;

int main() {
    int num = 5;

    int *ptr = &num;

    int **ptr2 = &ptr;

    cout << num << endl;
    cout << *ptr << endl;
    cout << **ptr2 << endl;

    return 0;
}