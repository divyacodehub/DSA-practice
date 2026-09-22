// LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal

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
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start > end)
        return NULL;

        int rootvalue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootvalue);

        int index = pos[rootvalue];

        root -> right = build(inorder, postorder, index + 1, end);
        root -> left = build(inorder, postorder, start, index - 1);

        return root;
    }    

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            pos[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1 ;

        return build(inorder, postorder, 0, inorder.size() - 1);

    }
};