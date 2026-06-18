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

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* add(Node* first, Node* second) {
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first != NULL)
            val1 = first->data;

        int val2 = 0;
        if(second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtTail(ansHead, ansTail, digit);

        if(first != NULL)
            first = first->next;

        if(second != NULL)
            second = second->next;
    }

    return ansHead;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first, second);

    ans = reverse(ans);

    return ans;
}

int main() {
    Node* first = new Node(4);
    first->next = new Node(5);

    Node* second = new Node(3);
    second->next = new Node(4);
    second->next->next = new Node(5);

    Node* ans = addTwoLists(first, second);
    print(ans);

    return 0;
}