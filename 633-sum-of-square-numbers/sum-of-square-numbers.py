class Solution:
    import math
    def judgeSquareSum(self, c: int) -> bool:
        low = 0
        high = math.isqrt(c)
        while low <= high:
            value = low*low + high*high
            if value == c:
                return True
            elif value < c:
                low += 1
            elif value > c:
                high -= 1
        return False