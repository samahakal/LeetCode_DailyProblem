// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxleft = 0, maxright = 0;
        
        int res = 0;
        
        while(left<=right){
            if(height[left]<height[right]){
                if(maxleft>height[left]){
                    res += maxleft - height[left];
                }
                else{
                    maxleft = height[left];
                }
                left++;
            }
            else{
                if(maxright>height[right]){
                    res += maxright - height[right];
                }
                else{
                    maxright = height[right];
                }
                right--;
            }
        }
        return res;
    }
};
