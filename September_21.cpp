// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// 985. Sum of Even Numbers After Queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        // even sum
        int even = 0;
        
        // nums and queries size
        int n = nums.size();
        int q = queries.size();
        
        // befor query even sum
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0) even+=nums[i];
        }
        
        vector<int>ans;
        
        
        // iterate in queries
        for(int i=0;i<q;i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            
            // remove num from even if it is
            if(nums[ind]%2 == 0){
                even -= nums[ind];
            }
            
            // update val
            nums[ind] += val;
            
            // if updated value is even then add itz
            if(nums[ind]%2 == 0){
                even += nums[ind];
            }
            ans.push_back(even);
        }
        return ans;
    }
};
