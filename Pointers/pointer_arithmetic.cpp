#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10,20,30,40,50};

    int *ptr = arr;

    cout << *ptr << endl;

    ptr++;

    cout << *ptr << endl;

    return 0;
}