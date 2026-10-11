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

Node* insertBST(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(8);

    root = insertBST(root, 3);
    root = insertBST(root, 10);
    root = insertBST(root, 1);
    root = insertBST(root, 6);
    root = insertBST(root, 14);
    root = insertBST(root, 4);

    cout << "BST in sorted order: ";
    inorder(root);

    return 0;
}