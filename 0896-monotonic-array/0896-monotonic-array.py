class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        increasing = True
        decreasing = True
        i = 1
        while i<len(nums):
            if nums[i] > nums[i-1]:
                decreasing = False

            if nums[i] < nums[i-1]:
                increasing = False
            
            i+=1
        return increasing or decreasing 