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

bool searchBST(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (target < root->data) {
        return searchBST(root->left, target);
    }

    return searchBST(root->right, target);
}

int main() {
    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    int target = 6;

    if (searchBST(root, target)) {
        cout << "Value found";
    } else {
        cout << "Value not found";
    }

    return 0;
}