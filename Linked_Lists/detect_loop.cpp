#include <iostream>
#include <map>
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

bool detectLoop(Node* head) {
    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n2; // loop

    cout << detectLoop(n1);

    return 0;
}