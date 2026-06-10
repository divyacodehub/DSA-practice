#include <iostream>
using namespace std;

string arr[10] = {
    "Zero","One","Two","Three","Four",
    "Five","Six","Seven","Eight","Nine"
};

void sayDigits(int n) {

    if(n == 0)
        return;

    int digit = n % 10;

    sayDigits(n / 10);

    cout << arr[digit] << " ";
}

int main() {
    int n = 412;

    sayDigits(n);

    return 0;
}