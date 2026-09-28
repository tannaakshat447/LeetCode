class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 0:
            return False
        b = bin(n)
        cnt = b.count('1')
        return cnt == 1