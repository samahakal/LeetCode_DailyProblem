// https://leetcode.com/problems/palindrome-pairs/
// 336. Palindrome Pairs
class Solution {
public:
    
    // check string is palindrome or not ?
    bool isPalindrome(string &a){
        int i = 0;
        int j = a.size()-1;
        while(i<j){
            if(a[i++]!=a[j--]) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>>ans;
        
        
        // store all words in map then reverse it
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            string key = words[i];
            reverse(key.begin(),key.end());
            mp[key] = i;
            
        }
        
        if(mp.find("")!=mp.end()){
            for(int i=0;i<n;i++){
                if(i == mp[""]) continue;
                if(isPalindrome(words[i])) ans.push_back({mp[""],i});
            }
        }
        
        // iterate on every word
        for(int i=0;i<n;i++){
            // iterate on word char 
            string curr  = words[i];
            int l = curr.size();
            for(int j=0;j<l;j++){
                string left = curr.substr(0,j);
                string right = curr.substr(j,l-j);
               
                if(mp.find(left)!=mp.end() and isPalindrome(right) and mp[left]!=i){
                    ans.push_back({i,mp[left]});
                }
                if(mp.find(right)!=mp.end() and isPalindrome(left) and mp[right]!=i){
                    ans.push_back({mp[right],i});
                }
    
            }
            
        }
        
        return ans;
        
    }
};
