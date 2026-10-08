class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        start = [0]
        end = []
        cnt = 0
        for i in range(len(s)):
            if s[i] == '(':
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                end.append(i)
                start.append(i+1)
        start.pop()
        res = []
        for i in range(len(s)):
            if i not in start and i not in end:
                res.append(s[i])
        
        return "".join(res)