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

int main() {

    // Creating the root
    Node* root = new Node(1);

    // Connecting left and right children
    root->left = new Node(2);
    root->right = new Node(3);

    // Adding children to node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Printing all nodes
    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;
    cout << "Left-Left: " << root->left->left->data << endl;
    cout << "Left-Right: " << root->left->right->data << endl;

    return 0;
}