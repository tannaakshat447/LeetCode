class Solution:
    def minBishopMoves(self, source: list[int], target: list[int]) -> int:
        if (source[0]+source[1])%2 != (target[0]+target[1])%2:
            return -1
        if source[0]==target[0] and source[1]==target[1]:
            return 0
        if (source[0]+source[1] == target[0]+target[1]) or (source[0]-source[1] == target[0]-target[1]):
            return 1
        else:
            return 2