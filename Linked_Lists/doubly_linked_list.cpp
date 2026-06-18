#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if(tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    if(head == NULL)
        return;

    if(position == 1) {
        Node* temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        return;
    }

    Node* curr = head;
    int cnt = 1;

    while(curr != NULL && cnt < position) {
        curr = curr->next;
        cnt++;
    }

    if(curr == NULL)
        return;

    if(curr->next != NULL)
        curr->next->prev = curr->prev;
    else
        tail = curr->prev;

    curr->prev->next = curr->next;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 5);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);

    print(head);

    deleteNode(head, tail, 3);
    print(head);

    return 0;
}