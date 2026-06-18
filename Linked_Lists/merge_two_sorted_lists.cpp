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

Node* merge(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if(l1 != NULL)
        tail->next = l1;

    if(l2 != NULL)
        tail->next = l2;

    Node* ans = dummy->next;
    delete dummy;

    return ans;
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);

    Node* b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);

    Node* ans = merge(a, b);
    print(ans);

    return 0;
}