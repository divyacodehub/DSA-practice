/* GFG - Predecessor and Successor in BST */

// Approach: BST Traversal

// Time: O(h)

// Space: O(1) auxiliary space


/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
        vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr -> data > key){
                suc = curr;
                curr = curr -> left;
            }
            
            else if(curr -> data < key){
                pre = curr;
                curr = curr -> right;
            }
            
            else{
                if(curr -> left != NULL){
                    Node* temp = curr -> left;
                    
                    while(temp -> right != NULL){
                        temp = temp -> right;
                    }
                    pre = temp;
                }
                if(curr -> right != NULL){
                    Node* temp = curr -> right;
                    
                    while(temp -> left != NULL){
                        temp = temp -> left;
                    }
                    suc = temp;
                }
                break;
            }
        }
        return{pre,suc};
    }
};