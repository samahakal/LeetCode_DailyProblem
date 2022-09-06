// 814. Binary Tree Pruning
// https://leetcode.com/problems/binary-tree-pruning/

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
    
    
    // postorder 
    
    bool solve(TreeNode* root){
        // base case
        if(root == NULL){
            return true;
        }
        
        // initialise both are false
        bool a = false, b = false;
      
        
        // check there is present zero in left child or not
        // if present then make root left child to NULL
        // similar for right child
        a = solve(root->left);
        if(a){
            root->left = NULL;
        }
    
    
        b = solve(root->right);
        if(b){
            root->right = NULL;
        }
    
        
        // if both child value are 0 and curr root also 0 then return true
        // ( when we return it true then it parent make it  NULL )
        if(a and b and root->val == 0){
            return true;
        }
        
        else return false
        return false;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        auto k = solve(root);
        if(k == true){
            return NULL;
        }
        return root;
    }
};
