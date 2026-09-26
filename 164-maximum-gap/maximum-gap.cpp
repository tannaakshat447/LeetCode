class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = abs(nums[0] - nums[1]);
        for(int i=1;i<n-1;i++){
            ans = max(ans, abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};