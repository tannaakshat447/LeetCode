#include <vector>

class Solution {
private:
    int search_first(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                if (mid != 0 && nums[mid - 1] != target) {
                    return mid;
                } else if (mid == 0) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    int search_last(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                if (mid != static_cast<int>(nums.size()) - 1 && nums[mid + 1] != target) {
                    return mid;
                } else if (mid == static_cast<int>(nums.size()) - 1) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = search_first(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = search_last(nums, target);
        return {first, last};
    }
};