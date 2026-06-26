// Stack Implementation using Array

#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main() {
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "Top element after pop: " << st.peek() << endl;

    if (st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}