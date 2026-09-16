class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        ans = set(nums)
        return len(ans) != len(nums)
        