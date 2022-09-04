// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// 987 -> Vertical Order Traversal of a Binary Tree



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
    
    void traverse(TreeNode* root,int diff,int level,map<int,map<int,multiset<int>>>&mp){
        if(root){
            mp[diff][level].insert(root->val);
            traverse(root->left,diff-1,level+1,mp);
            traverse(root->right,diff+1,level+1,mp);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // to store nodes
        // map < vertical distance, map < level, elements store in set at that level >> mp
        map<int,map<int,multiset<int>>>mp;
        
        traverse(root,0,0,mp);        
        
        // to store ans
        vector<vector<int>>ans;
        for(auto a : mp){
            vector<int>col;            // col
            for(auto b : a.second){
                col.insert(col.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    
};
