// https://leetcode.com/problems/utf-8-validation/
// 393. UTF-8 Validation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 0;
        int n = data.size();
        
        int mask1 = 0x80;
        int mask2 = 0x20;
        int mask3 = 0x10;
        int mask4 = 0x08;
        
        int check = 0xC0;
        
        for(int i=0;i<n;i++){
   
            if((check & data[i]) == mask1){
                return false;
            }
            
            bytes = 0;
            
            if((mask1 & data[i]) == 0){
                continue;
            }
            
            else if((mask2 & data[i]) == 0){
                bytes = 1;
            }
            else if((mask3 & data[i]) == 0){
                bytes = 2;
            }
            else if((mask4 & data[i]) == 0){
                bytes = 3;
            }
            else{
                return false;
            }
            
            while(bytes--){
                i++;
                if(i>=data.size() || ((check & data[i]) != mask1)){
                    return false;
                }
            }
               
        }
        return true;
    }
};
