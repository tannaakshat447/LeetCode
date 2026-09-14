class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // currentSum = max(nums[i], currentSum + nums[i]);
            if(currentSum + nums[i] > nums[i]) currentSum = currentSum + nums[i];
            else currentSum = nums[i];
            // maxSum = max(maxSum, currentSum);
            if(currentSum > maxSum) maxSum = currentSum;
        }

        return maxSum;
    }
};