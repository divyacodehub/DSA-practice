#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10,20,30,40,50};

    cout << arr << endl;
    cout << &arr[0] << endl;

    int *ptr = arr;

    cout << *ptr << endl;
    cout << *(ptr + 2) << endl;

    return 0;
}