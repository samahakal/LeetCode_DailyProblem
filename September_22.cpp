// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// 557. Reverse Words in a String III

class Solution {
public:
    string reverseWords(string s) {

        int curr = 0;
        int n = s.length();
   
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(s.begin()+curr,s.begin()+i);
                curr = i+1;
            }
        }
        reverse(s.begin()+curr,s.end());
        return s;
    }
};
