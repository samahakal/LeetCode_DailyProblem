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

// Average of Levels in Binary Tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        long ans = 0;
        vector<double>v;
        
        while(!q.empty()){
            int n = q.size();
            ans = 0;
       
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                ans += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            v.push_back((double)ans/n);
        }
        return v;
    }
};
