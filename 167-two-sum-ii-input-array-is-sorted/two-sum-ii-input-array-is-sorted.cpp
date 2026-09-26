class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0;
        int idx2 = numbers.size()-1;
        vector<int> ans(2);

        while(idx1 != idx2){

            if(numbers[idx1] + numbers[idx2] == target){
                ans[0] = idx1 + 1;
                ans[1] = idx2 + 1;
                return ans;
            }

            else if(numbers[idx1] + numbers[idx2] < target){
                idx1++;
            }

            else if(numbers[idx1] + numbers[idx2] > target){
                idx2--;
            }

        }

        return ans;

    }
};