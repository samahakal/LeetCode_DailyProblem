// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// 718. Maximum Length of Repeated Subarray


class Solution {
public:
    
    // Dynamic Programming 
    // TC : O(n*m)
    // SC : O(n*m)
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        
        
        // to optimie space
        if(n<m){
            return findLength(nums1,nums2);
        }
        int ans = 0;
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int prev = 0;
        int curr = 0;
        for(int i=1;i<=n;i++){
            prev = 0;
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr = 1 + curr;
                    ans = max(ans,curr);
                }
                else{
                    curr = 0;
                }
                prev = curr;
                
                
            }
        }
        return ans;
    }
};
