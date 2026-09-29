class Solution:
    def intersection(self, nums: list[list[int]]) -> list[int]:
        if len(nums) == 1:
            return sorted(nums[0])
        common = list(set(nums[0]).intersection(set(nums[1])))
        for i in range(2, len(nums)):
            common = list(set(nums[i]).intersection(set(common)))
        return sorted(common)