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

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//checking if k nodes exist
Node* kReverse(Node* head, int k) {
    if(head == NULL)
        return NULL;

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    if(cnt < k)
        return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    cnt = 0;

    while(curr != NULL && cnt < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    if(forward != NULL)
        head->next = kReverse(forward, k);

    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    print(head);

    head = kReverse(head, 3);

    print(head);

    return 0;
}