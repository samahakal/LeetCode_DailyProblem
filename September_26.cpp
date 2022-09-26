// https://leetcode.com/problems/satisfiability-of-equality-equations/submissions/
// 990. Satisfiability of Equality Equations


class Solution {
public:
    
    
    // store parent
    int arr[26];
    
    // find parent
    int par(int x){
        if(x == arr[x]) return x;
        return arr[x] = par(arr[x]);
    }
    
    
    // solution
    bool equationsPossible(vector<string>& equations) {
        
        // every node is parent of it's self
        for(int i=0;i<26;i++) arr[i] = i;
        
        // for '='
        for(auto e : equations){
            char a = e[0];
            char b = e[3];
            
            if(e[1] == '=') arr[par(a-'a')] = par(arr[b-'a']);
        }
        
        // for '!'
        for(auto e : equations){
            char a = e[0];
            char b = e[3];
            
            if(e[1] == '!' and par(a-'a') == par(b-'a')) return false; 
        }
        return true;
    }
};
