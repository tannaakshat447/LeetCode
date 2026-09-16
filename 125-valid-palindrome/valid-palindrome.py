class Solution:
    def isPalindrome(self, s: str) -> bool:
        final = ""
        for i in s:
            if i.isalnum():
                final += i.lower()
        if final == final[::-1]:
            return True
        else:
             return False