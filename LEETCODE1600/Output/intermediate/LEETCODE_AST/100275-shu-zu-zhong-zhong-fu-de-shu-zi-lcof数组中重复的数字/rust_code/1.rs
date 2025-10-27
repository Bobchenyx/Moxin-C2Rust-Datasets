python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i, j in enumerate(nums):
            if nums[i] == nums[j] and i != j:
                return nums[j]
            nums[i], nums[j] = nums[j], nums[i]