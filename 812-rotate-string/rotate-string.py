class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        else:
            s += s
            if goal in s:
                return True
            else:
                return False