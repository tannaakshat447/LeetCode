class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater =0;
        int left = 0;
        int right = height.size()-1;
        for(int i=0;i<height.size();i++){
            if((right - left)*min(height[left],height[right])>maxwater) maxwater = (right - left)*min(height[left],height[right]);
            if(height[left]<=height[right]) left++;
            else right--; 
        }

        return maxwater;
    }
};