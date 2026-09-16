class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        ans = set(nums)
        if len(ans) == len(nums):
            return False
        else:
            return True
        