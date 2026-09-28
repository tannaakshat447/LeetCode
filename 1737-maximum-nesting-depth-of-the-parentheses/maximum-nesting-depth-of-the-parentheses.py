class Solution:
    def maxDepth(self, s: str) -> int:
        m = 0
        curr = 0
        for i in s:
            if i == "(":
                curr += 1
                m = max(m, curr)
            if i == ")":
                curr -= 1
        return m