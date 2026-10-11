#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* findMax(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

int main() {
    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    Node* minimum = findMin(root);
    Node* maximum = findMax(root);

    if (minimum != NULL) {
        cout << "Minimum: " << minimum->data << endl;
    }

    if (maximum != NULL) {
        cout << "Maximum: " << maximum->data << endl;
    }

    return 0;
}