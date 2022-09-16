// 2007. Find Original Array From Doubled Array
// https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // to store answer
        vector<int>ans;
        vector<int>ans_e;
        
        unordered_map<int,int>mp;
        
        // sort in increasing order
        sort(changed.begin(),changed.end());
        
        
        // check k/2 present or not in map else put k into map
        for(int i=0;i<changed.size();i++){
            int k = changed[i];
            if(k%2==0 and (mp.find(k/2) != mp.end())){
                ans.push_back(k/2);
                mp[k/2]--;
                if(mp[k/2] == 0){
                    mp.erase(k/2);
                }
            }
            else{
                mp[k]++;
            }              
        }
        if(mp.empty()){
            return ans;
        }
        return ans_e;
    }
};
