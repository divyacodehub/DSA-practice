// Queue using Array
// Approach: Array implementation
// Time: O(1) for enqueue/dequeue
// Space: O(n)

#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    void enqueue(int x) {
        if (rear == 100) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[rear] = x;
        rear++;
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue Underflow" << endl;
            return;
        }

        front++;
    }

    int getFront() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << endl;

    q.dequeue();

    cout << q.getFront() << endl;

    return 0;
}