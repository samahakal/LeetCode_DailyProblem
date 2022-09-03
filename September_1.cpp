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
//  link -> https://leetcode.com/problems/count-good-nodes-in-binary-tree/
//  Count Good Nodes in Binary Tree
class Solution {
public:
    
    int cnt = 0;
    void dfs(TreeNode *root,int mx){
        if(root == NULL){
            return;
        }
        
        if(root->val >= mx){
            cnt++;
            mx = max(mx,root->val);
        }
        dfs(root->left,mx);
        dfs(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return cnt;
    }
};
