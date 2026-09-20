def search_first(nums: list[int], target: int) -> int:
    low = 0
    high = len(nums) - 1
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:
            if mid != 0 and nums[mid-1] != target:
                return mid
            elif mid == 0:
                return mid
            else:
                high = mid - 1
        elif nums[mid] < target:
            low = mid + 1
        elif nums[mid] > target:
            high = mid - 1
    return -1

def search_last(nums: list[int], target: int) -> int:
    low = 0
    high = len(nums) - 1
    while low <= high:
        mid = (low + high) // 2
        if nums[mid] == target:
            if mid != len(nums) - 1 and nums[mid+1] != target:
                return mid
            elif mid == len(nums) - 1:
                return mid
            else:
                low = mid + 1
        elif nums[mid] < target:
            low = mid + 1
        elif nums[mid] > target:
            high = mid - 1
    return -1

class Solution:
    
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        first = search_first(nums, target)
        if first == -1:
            return [-1, -1]
        last = search_last(nums, target)
        ans = [first, last]
        return ans