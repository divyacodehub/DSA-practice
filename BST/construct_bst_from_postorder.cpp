// Problem: Construct BST from Postorder Traversal
// Approach: Recursion with Lower and Upper Bounds
// Time Complexity: O(n)
// Space Complexity: O(h)


/* Structure of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:

        Node* solve(vector<int>& post, int& i, int lower, int upper) {
            if(i < 0 || post[i] < lower || post[i] > upper)
                return nullptr;

            Node* root = new Node(post[i]);
            i--;

            root->right = solve(post, i, root->data, upper);
            root->left = solve(post, i, lower, root->data);

            return root;
        }

  
        Node* constructTree(vector<int>& post) {
            int i = post.size() - 1;
            return solve(post, i, INT_MIN, INT_MAX);
    }
};