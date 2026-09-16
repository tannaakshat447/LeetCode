class Solution:
    def isPali(self, s: str) -> bool:
        return s == s[::-1]

    def longestPalindrome(self, s: str) -> str:
        ans = s[0]
        for i in range (1, len(s)+1):
            for j in range(0, len(s)-i+1):
                sub = s[j:j+i]
                if len(sub) > len(ans) and self.isPali(sub):
                    ans = sub
        return ans