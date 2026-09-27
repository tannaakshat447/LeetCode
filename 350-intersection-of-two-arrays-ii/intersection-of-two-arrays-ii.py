from collections import Counter

class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        counts = Counter(nums1)
        ans = []
        for num in nums2:
            if counts.get(num, 0) > 0:
                ans.append(num)
                counts[num] -= 1

        return ans