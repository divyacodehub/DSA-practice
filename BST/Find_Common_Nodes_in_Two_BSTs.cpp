/* GFG - Find Common Nodes in Two BSTs */

// Approach: Inorder Traversal + Two Pointers

// Time: O(n + m)

// Space: O(n + m)


/* Structure of a Binary Search Tree node
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
  void inorder(Node* root, vector<int>& arr){
      if(root == NULL)
      return ;
      
      inorder(root -> left, arr);
      arr.push_back(root -> data);
      inorder(root -> right, arr);
  }
  
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> arr1, arr2, ans;
         
        inorder(r1, arr1);
        inorder(r2, arr2);
        
        int i = 0, j = 0;
        
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            
            else if (arr1[i] > arr2[j]){
                    j++;
            }
                    
            else{
                    i++;
                }
            }
        return ans;
    }
};