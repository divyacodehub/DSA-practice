// Two Stacks in an Array

#include <iostream>
using namespace std;

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop1() {
        if (top1 >= 0) {
            top1--;
        } else {
            cout << "Stack 1 Underflow" << endl;
        }
    }

    void pop2() {
        if (top2 < size) {
            top2++;
        } else {
            cout << "Stack 2 Underflow" << endl;
        }
    }

    int peek1() {
        if (top1 >= 0)
            return arr[top1];
        return -1;
    }

    int peek2() {
        if (top2 < size)
            return arr[top2];
        return -1;
    }
};

int main() {
    TwoStack st(6);

    st.push1(10);
    st.push1(20);
    st.push2(100);
    st.push2(200);

    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    st.pop1();
    st.pop2();

    cout << "After pop:" << endl;
    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    return 0;
}