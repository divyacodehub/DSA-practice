// GFG - Kth Largest Element in BST

// Approach: Reverse Inorder Traversal

// Time: O(n)

// Space: O(h)


/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:            
      int count = 0;
      int ans = 0;
      bool found = false;
    
    
      void reverseInorder(Node* root, int k){
        if(root == NULL || found)
            return;

        reverseInorder(root -> right, k);

        if(found)
          return;

        count++;

        if(count == k){
        ans = root -> data;
        found = true;
        return;
        }
        
        reverseInorder(root -> left, k);
    }
  
    int kthLargest(Node *root, int k) {
        reverseInorder(root, k);
        return ans;
        
    }
};