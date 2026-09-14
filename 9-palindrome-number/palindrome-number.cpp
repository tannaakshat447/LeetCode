class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;   // negative numbers not palindrome

        string s = to_string(x);
        int count = s.length();

        for (int i = 0; i < count / 2; i++) {
            if (s[i] != s[count - i - 1])
                return false;
        }
        return true;
    }
};