// LeetCode 889 - Construct Binary Tree from Preorder and Postorder Traversal

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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int start, int end) {
        if(start > end)
        return NULL;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        if(start == end)
        return root;

        int leftrootvalue = preorder[preIndex];

        int index = pos[leftrootvalue];

        root -> left = build(preorder, postorder, start, index);
        root -> right = build(preorder, postorder, index + 1, end - 1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++){
            pos[postorder[i]] = i;
        }
        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};