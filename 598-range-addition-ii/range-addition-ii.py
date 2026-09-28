class Solution:
    def maxCount(self, m: int, n: int, ops: list[list[int]]) -> int:
        minrow = m
        mincol = n
        for i, j in ops:
            minrow = min(minrow, i)
            mincol = min(mincol, j)
        return minrow * mincol