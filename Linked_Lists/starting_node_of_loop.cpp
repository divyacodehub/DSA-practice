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

Node* floydDetect(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return slow;
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetect(head);

    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // loop starts at 20

    Node* ans = getStartingNode(n1);

    if(ans)
        cout << ans->data;

    return 0;
}