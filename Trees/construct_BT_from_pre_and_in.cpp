// LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal 

// Approach: Recursion + Hash Map 

// Time: O(n) 

// Space: O(n)


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
    unordered_map <int,int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end)
        return NULL;

        int rootvalue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootvalue);

        int index = pos[rootvalue];

        root -> left = build(preorder, inorder, start, index - 1);
        root -> right = build(preorder, inorder, index + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};