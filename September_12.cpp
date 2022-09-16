// https://leetcode.com/problems/bag-of-tokens/
// 948. Bag of Tokens
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int n = tokens.size();
        int i=0;
        int j = n-1;
        
        int ans = 0;
        int curr = 0;
        while(i<=j){
            if(tokens[i]<=power){
                power -= tokens[i];
                curr++;
                i++;
            }
            else if(curr>0){
                power += tokens[j];
                j--;
                curr--;
            }
            else{
                break;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
