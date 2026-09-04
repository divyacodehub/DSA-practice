// LeetCode 145 - Binary Tree Postorder Traversal

// Approach: Recursion

// Time: O(n)

// Space: O(h)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void postorder(TreeNode* root,vector<int> &ans){
        //base case
        if (root == NULL)
        return;

        postorder(root -> left, ans);  //left
        postorder(root -> right, ans);  //right
        ans.push_back(root -> val);  //root

    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};