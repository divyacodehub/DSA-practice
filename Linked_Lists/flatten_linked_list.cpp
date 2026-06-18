#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int d) {
        data = d;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge(Node* a, Node* b) {
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    Node* result;

    if(a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

Node* flatten(Node* root) {
    if(root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    //Usually tested on platform input
    return 0;
}