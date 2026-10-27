// LeetCode 108 - Convert Sorted Array to Binary Search Tree

// Approach: Recursion (Divide and Conquer)

// Time: O(n)

// Space: O(log n) auxiliary stack


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

    TreeNode* build(vector<int>& nums, int start, int end) {
        if(start > end)
        return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root -> left = build(nums, start, mid - 1);

        root -> right = build(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums , 0, nums.size() - 1);
    }
};