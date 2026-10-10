class Solution:
    def minSumSquareDiff(
        self, nums1: list[int], nums2: list[int], k1: int, k2: int
    ) -> int:
        abs_arr = sorted(
            [abs(a - b) for a, b in zip(nums1, nums2)],
            reverse=True
        )
        ope = k1 + k2

        if ope >= sum(abs_arr):
            return 0

        n = len(abs_arr)
        abs_arr.append(0)

        for i in range(n):
            count = i + 1
            gap = abs_arr[i] - abs_arr[i + 1]
            needed = gap * count

            if ope >= needed:
                ope -= needed
            else:
                decrease, extra = divmod(ope, count)
                level = abs_arr[i] - decrease

                return (
                    (count - extra) * level * level
                    + extra * (level - 1) * (level - 1)
                    + sum(d * d for d in abs_arr[i + 1:])
                )

        return 0