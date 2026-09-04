#include <iostream>
using namespace std;

// A node of a Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Preorder: Root -> Left -> Right
void preorder(Node* root) {

    // Base case
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {

    // Base case
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {

    // Base case
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

int main() {

    // Creating the tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Traversals
    cout << "Preorder: ";
    preorder(root);

    cout << endl;

    cout << "Inorder: ";
    inorder(root);

    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    cout << endl;

    return 0;
}s