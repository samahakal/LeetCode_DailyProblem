// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// 1457. Pseudo-Palindromic Paths in a Binary Tree
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
    
    int dfs(TreeNode* root,int path){
        
        // base case
        if(root == NULL){
            return 0;
        }
        
        // store val
        int data = root->val;
        
        // add into path 
        path ^= (1<<data);
        
        // check root is leaf or not if yes then check total odd present in path
        if(root->left == NULL and root->right == NULL){
            if((path & (path-1)) == 0){
                return 1;
            }
            return 0;
        }
        // call left and right child
        return dfs(root->left,path) + dfs(root->right,path);
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
         return dfs(root,0);
    }
};
