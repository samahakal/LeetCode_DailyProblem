// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// 1680. Concatenation of Consecutive Binary Numbers

# Method 1 : Brute
# TC : O(nlog(n))
# SC : O(1)

    
    // calculate binary number length
    long long len(long long x){
        return floor(log2(x))+1;
    }
    
    
    // power function (x^n)%mod
    long long pow(long x,long n,long mod){
        long long ans = 1;
        while(n){
            if(n%2!=0){
                ans *= x;
                ans %= mod;
                n--;
            }
            else{
                x *= x;
                x %= mod;
                n /= 2;
            }
        }
        return ans;
    }
    
    // solution 
    int concatenatedBinary(int n) {
        
        long long ans = 1;
        long long mod = 1e9+7;
        long long mul;
        
        for(int i=2;i<=n;i++){
            long long l = len(i);
            mul = pow(2,l,mod)%mod;
            ans = ((ans%mod)*(mul%mod)+i)%mod;
        }
        return ans%mod;
        
    }

  
# Method 2 : Optimal (using bit manipulation)
# TC : O(n)
# SC : O(1)

    
    int concatenatedBinary(int n) {        
        long ans = 1;
        long mod = 1e9+7;
        long len = 1;
        
        // length will be increment as pow of 2 occur
        for(int i=2;i<=n;i++){
            if((i & (i-1)) == 0){
                len++;
            }
            
            ans = ((ans<<len)%mod + i)%mod; 
        }
        return ans%mod;
    }

## HAPPY CODING:)

