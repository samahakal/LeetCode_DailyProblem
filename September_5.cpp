// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>ans;
        
        if(root == NULL){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int si = q.size();
            
            vector<int>add;
            for(int i=0;i<si;i++){
                auto node = q.front();
                add.push_back(node->val);
                
                q.pop();
                
                
                for(auto ch : node->children){
                    q.push(ch);                    
                }
            }
            ans.push_back(add);
                        
        }
        return ans;
        
    }
};
