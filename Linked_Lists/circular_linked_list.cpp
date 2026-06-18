#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

void print(Node* tail) {
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);

    cout << endl;
}

void insertNode(Node* &tail, int element, int d) {

    // Empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    Node* curr = tail;

    while(curr->data != element)
        curr = curr->next;

    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(Node* &tail, int value) {

    if(tail == NULL)
        return;

    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    if(curr == prev)
        tail = NULL;
    else if(tail == curr)
        tail = prev;

    delete curr;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 0, 10);
    print(tail);

    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);

    print(tail);

    deleteNode(tail, 30);
    print(tail);

    return 0;
}