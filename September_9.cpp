// 1996. The Number of Weak Characters in the Game
// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/submissions/

class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]){
            return a[1]>b[1];             // for strictly incresing 
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        
        // sort in one parameter and compare in another parameter
        // sort on attack
        sort(properties.begin(),properties.end(),cmp);

        int mn = INT_MIN;
        int ans = 0;
        
        
        // compare on defence
        for(int i=properties.size()-1;i>=0;i--){
            if(properties[i][1]<mn){
                ans++;
            }
            mn = max(mn,properties[i][1]);
        }
        return ans;
    }
};
