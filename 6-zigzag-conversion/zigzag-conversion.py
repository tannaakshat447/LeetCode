class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        ans = ""
        cycle = 2 * (numRows - 1)

        for i in range(numRows):
            j = i

            while j < len(s):
                ans += s[j]

                diagonal = j + cycle - 2 * i

                if i != 0 and i != numRows - 1 and diagonal < len(s):
                    ans += s[diagonal]

                j += cycle

        return ans