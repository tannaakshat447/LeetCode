class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& final_ans, int idx){
        if(idx==nums.size()){
            final_ans.push_back(ans);
            return;
        }
        helper(nums, ans, final_ans, idx+1);
        ans.push_back(nums[idx]);
        helper(nums, ans, final_ans, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final_ans;
        vector<int> ans;
        helper(nums, ans, final_ans, 0);
        return final_ans;
    }
};