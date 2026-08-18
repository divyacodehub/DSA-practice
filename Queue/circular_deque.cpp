// LeetCode 641 - Design Circular Deque
// Approach: Circular Array
// Time: O(1) for insertion/deletion
// Space: O(n)

class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};