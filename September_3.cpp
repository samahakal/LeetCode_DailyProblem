class Solution {
public:
  
//   Link -> https://leetcode.com/problems/numbers-with-same-consecutive-differences/
    
    vector<int>ans;
    
    void dfs(int num,int n,int k){
        // base case
        if(n == 1){
            ans.push_back(num);
            return;
        }
        
        
        int last = num%10;
        // check addition of k and last is less than 10 
        if(last + k < 10){
            dfs(num*10 + last + k, n-1, k);
        }
        
        // check substraction is greater than or equal to 0 or not
        if(k!=0 and last - k >=0){
            dfs(num*10 + last - k , n-1,k);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            dfs(i,n,k);
        }
        return ans;
    }
};
