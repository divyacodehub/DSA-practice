#include <iostream>
using namespace std;

void update(int *p) {
    *p = *p + 10;
}

int main() {
    int value = 5;

    update(&value);

    cout << value << endl;

    return 0;
}