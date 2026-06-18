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

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

bool isPalindrome(Node* head) {
    if(head == NULL || head->next == NULL)
        return true;

    Node* middle = getMiddle(head);
    middle->next = reverse(middle->next);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL) {
        if(head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(2);
    Node* d = new Node(1);

    a->next = b;
    b->next = c;
    c->next = d;

    cout << isPalindrome(a);

    return 0;
}