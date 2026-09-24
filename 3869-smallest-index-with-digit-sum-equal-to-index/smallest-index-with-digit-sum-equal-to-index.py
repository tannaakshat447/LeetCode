def sum_digits(x: int) -> int:
    s = 0
    while x > 0:
        s += x%10
        x //= 10
    return s

class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(0, len(nums)):
            if i == sum_digits(nums[i]):
                return i
        return -1
        