// LeetCode 297 - Serialize and Deserialize Binary Tree

// Approach: Preorder Traversal + Recursion

// Time: O(n)

// Space: O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    int index = 0;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
        return "#,";

        return to_string(root -> val) + "," +
               serialize(root -> left) +
               serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        index = 0;
        return build(data);
    }
        TreeNode* build (string &data){

        string value = "";

        while(data[index] != ','){
            value += data[index];
            index ++;
        }

        index ++;

        if(value == "#")
        return NULL;

        TreeNode* root = new TreeNode (stoi(value));

        root -> left = build(data);
        root -> right = build(data);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));