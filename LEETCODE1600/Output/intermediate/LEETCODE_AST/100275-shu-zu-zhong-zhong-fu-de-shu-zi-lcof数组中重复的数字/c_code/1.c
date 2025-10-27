python3 []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        S = set()
        for n in nums:
            if n in S:
                return n
            S.add(n)