class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if(len(nums) == 0):
            return 0
        nums.sort()
        maxi = 1
        current = 1
        i = 1
        while i<len(nums):
            if nums[i] == nums[i-1]+1:
                current+=1
            elif nums[i] == nums[i-1]:
                pass
            else:
                current = 1
            if current > maxi:
                maxi = current
            i+=1
        return maxi

        