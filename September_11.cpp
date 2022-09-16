// https://leetcode.com/problems/maximum-performance-of-a-team/
// 1383. Maximum Performance of a Team
class Solution {
public:
    
    long mod = 1000000007;
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        // speed and efficiency
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i].first = speed[i];
            v[i].second = efficiency[i];
        }
        
        // sort on efficiency in decreasing order
        sort(v.begin(),v.end(),cmp);
        
        
        // iterage on loop
        long long ans = 0;
        long long curr = 0;
        long long mn = 1e6;
        
        priority_queue<int,vector<int>,greater<int>>p;        
        for(int i=0;i<k;i++){
            curr += v[i].first;
            mn = v[i].second;
            ans = max(ans,curr*mn);
            p.push(v[i].first);
        }
        
        
        for(int i=k;i<n;i++){
            if(p.top()<v[i].first){
                curr = curr - p.top() + v[i].first;
                mn = v[i].second;
                ans = max(ans,curr*mn);
                p.pop();
                p.push(v[i].first);
            }
            
        }
        return int(ans%mod);
    }
};
