// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    
    string ans = "";    
    
    // preorder 
    void dfs(TreeNode* root){
        
        // base case
        if(root == NULL){
            return;
        }
        
        // add to string
        ans += to_string(root->val);
        
        // call root left
        if(root->left){
            ans += '(';
            dfs(root->left);     
            ans += ')';
        }
        
        // if right not present then add "()"
        else if(root->right != NULL){
            ans += "()";
        }
        
        // call root right
        if(root->right){
            ans += '(';
            dfs(root->right);
            ans += ')';
        }
        
        return;
    }
    
    string tree2str(TreeNode* root) {
        ans = "";
        dfs(root);
        return ans;
    }
};
