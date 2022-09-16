// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// 188. Best Time to Buy and Sell Stock IV
class Solution {
public:
    
    int solve(int ind,vector<int>&price,int k,vector<vector<int>>&dp){
        // base case
        if(ind == price.size() || k == 0){
            return 0;
        }
        
        // already calculate 
        int &ans = dp[ind][k];
        if(ans != -1){
            return ans;
        }
        int call1 = 0;
        int call2 = 0;
        
        // buy
        if(k%2 == 0){
            call1 = -price[ind] + solve(ind+1,price,k-1,dp);
        }
        
        // sell
        else if(k%2 != 0){
            call1 = price[ind] + solve(ind+1,price,k-1,dp);     
        }
        
        // neither buy nor sell
        call2 = solve(ind+1,price,k,dp);
        return ans = max(call1,call2);
    }
    
    int maxProfit(int k, vector<int>& price) {
        vector<vector<int>>dp(price.size(),vector<int>(2*k+1,-1));
        return solve(0,price,2*k,dp);
    }
};
