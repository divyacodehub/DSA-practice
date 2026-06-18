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

void removeLoop(Node* head) {
    Node* start = getStartingNode(head);

    if(start == NULL)
        return;

    Node* temp = start;

    while(temp->next != start) {
        temp = temp->next;
    }

    temp->next = NULL;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n2; // loop

    removeLoop(n1);

    cout << "Loop removed";

    return 0;
}