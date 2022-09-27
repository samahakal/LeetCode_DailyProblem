// https://leetcode.com/problems/push-dominoes/
// 838. Push Dominoes

class Solution {
public:
    string ans = "";
    
    void solve(string st){
        
        int n = st.size();
        int a = 0;
        int b = n-1;
        
        string ad1 = "";
        string ad2 = "";
        
        
        // all are 'L'
        if(st[a] != 'R'){
            string ad(b+1,'L');
            ans += ad;
            return;
        }
        
        
        // half 'R' and half 'L'
        while(a<b){
            ad1 += 'R';
            ad2 += 'L';
            a++;
            b--;
        }
        reverse(ad2.begin(),ad2.end());
        if(a == b){
            ad1 += '.';
        }
        ans += ad1 + ad2;
    }

    string pushDominoes(string dominoes) {
        // size
        int n = dominoes.size();
        
        // store string
        ans = "";
        
        // for iteration
        string st;
        
        // for loop
        for(int i=0;i<n;i++){
            // push into st
            st.push_back(dominoes[i]);
            
            // solve function
            if(dominoes[i] == 'L'){
                solve(st);
                st = "";
            }
            
            // add string between two 'R' [include first 'R'] i.e -> R...R or RR
            else if(st[0]=='R' and st[st.size()-1]=='R'){
                string ad(st.size()-1,'R');
                ans += ad;
                st = "R";
            }
            // add string i.e -> ...R 
            else if(dominoes[i] == 'R' and st.size()>0){
                // solve1(st);
                st.pop_back();
                ans += st;
                st = "R";
            }
            
        }
        
        // if st is not empty
        if(st.size()!=0){
            
            // last is 'R' then convert all string to 'R' string
            if(st[0]=='R'){
                string ad(st.size(),'R');
                ans += ad;
            }
            else{
                ans += st;
            }
            
        }
        
        return ans;
    }
};



//  solution 2 -> O(n) 
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        vector<int>r(n,0);
        vector<int>l(n,0);
        
  
        int k = 0;
        for(int i=0;i<n;i++){
            if(dominoes[i] == 'L'){
                k = 0;
            }
            if(dominoes[i] == 'R'){
                k = n;
            }
            r[i] = k;
            k--;
            if(k<0){
                k = 0;
            }
        }
        
        k = 0;
        
        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'R'){
                k = 0;
            }
            if(dominoes[i] == 'L'){
                k = -n;
            }
            
            l[i] = k;
            k++;
            if(k>0){
                k = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            if(r[i]+l[i] > 0){
                dominoes[i] = 'R';
            }
            else if(r[i]+l[i] < 0){
                dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};
