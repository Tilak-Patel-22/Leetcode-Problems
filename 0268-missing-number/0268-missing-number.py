class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        nums.sort()
        j = 0
        i=0
        n = len(nums)
        while i<n:
            if j == nums[i]:
                i+=1
                j+=1
            elif j!=nums[i]:
                return j
        return j
