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

bool isCircular(Node* head) {
    if(head == NULL)
        return true;

    Node* temp = head->next;

    while(temp != NULL && temp != head)
        temp = temp->next;

    if(temp == head)
        return true;

    return false;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    cout << isCircular(n1);

    return 0;
}