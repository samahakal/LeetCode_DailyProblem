// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/
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
    
    // to store ans
    vector<vector<int>>ans;
    
    // dfs 
    void dfs(TreeNode* root,int targetSum,vector<int>st){
        
        // base case
        if(root == NULL){
            return;
        }
        
        // last node 
        if(root->left == NULL and root->right == NULL){
            // path find
            if(targetSum == root->val){
                st.push_back(root->val);
                ans.push_back(st);
            }
            return;
        }
        targetSum -= root->val;
        st.push_back(root->val);
        dfs(root->left,targetSum,st);
        dfs(root->right,targetSum,st);
        
    }
    
    // given function
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>st;
        dfs(root,targetSum,st);
        return ans;
        
    }
};
