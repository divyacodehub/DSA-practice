// Queue using Linked List
// Approach: Linked List
// Time: O(1) for enqueue/dequeue
// Space: O(n)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    int getFront() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
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