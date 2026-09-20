class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        line_cnt = 1
        width = 0
        for letter in s:
            if width +  widths[ord(letter) - 97] > 100:
                line_cnt += 1
                width = 0
            width += widths[ord(letter) - 97]
        return [line_cnt, width]