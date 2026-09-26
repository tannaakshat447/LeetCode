class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()%2 != 0){
            return nums[((nums.size()+1)/2)-1];
        }
        else return nums[nums.size()/2];
    }
};