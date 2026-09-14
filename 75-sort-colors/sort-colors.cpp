class Solution {
public:
    void swap(int& x,int& y){
        int temp = x;
        x = y;
        y = temp;
    }
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = (nums.size()-1);

        while(mid<=hi){
            if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }

            else if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }

            else if(nums[mid]==1){
                mid++;
            }
        }
    }
};