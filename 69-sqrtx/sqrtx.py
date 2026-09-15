class Solution:
    def mySqrt(self, x: int) -> int:
        i=1
        while True:
            if i*i == x:
                return i
            elif i*i > x:
                return i-1
            else:
                i += 1