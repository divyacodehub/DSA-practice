// LeetCode 117 - Populating Next Right Pointers in Each Node II

// Approach: Level Order using Next Pointers

// Time: O(n)

// Space: O(1)


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        return NULL;

        Node* current = root;

        while(current != NULL){
            Node* dummy = new Node(0);
            Node* tail = dummy;

            while(current != NULL){
                if(current -> left != NULL){
                    tail -> next = current -> left;
                    tail = tail -> next;
                }

                if(current -> right != NULL){
                    tail -> next = current -> right;
                    tail = tail -> next;
                }

                current = current -> next;

            }

            current = dummy -> next;

        }

        return root;
        
    }
};