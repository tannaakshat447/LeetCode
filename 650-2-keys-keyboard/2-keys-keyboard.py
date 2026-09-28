class Solution:
    def minSteps(self, n: int) -> int:
        strlen = 1
        copy = 1
        ope = 0
        while strlen < n:
            if (n - strlen) % strlen == 0:
                copy = strlen
                strlen += copy
                ope += 2
            else:
                strlen += copy
                ope += 1
        return ope