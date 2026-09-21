#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k, 0);
        std::vector<long long> dp(k, 0);

        for (int val : nums) {
            std::vector<long long> next_dp(k, 0);
            int current_rem = val % k;
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (1LL * r * current_rem) % k;
                    next_dp[next_rem] += dp[r];
                }
            }

            next_dp[current_rem] += 1;

            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return result;
    }
};