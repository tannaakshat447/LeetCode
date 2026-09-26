class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] < target){
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};