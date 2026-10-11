// GFG - Bottom View of Binary Tree

// Approach: BFS + Map

// Time: O(n log n)

// Space: O(n)



/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
           vector<int> ans;

           if(root == NULL)
           return ans;

           map<int,int> mp;
           queue<pair<Node*,int>> q;

           q.push({root, 0});

           while(!q.empty()){
               auto[node, hd] = q.front();
               q.pop();

               mp[hd] = node -> data;

               if(node -> left)
               q.push({node -> left, hd - 1});

               if(node -> right)
               q.push({node -> right, hd + 1});


           }
            for(auto it : mp){
               ans.push_back(it.second);
           }
           return ans;

    }
};