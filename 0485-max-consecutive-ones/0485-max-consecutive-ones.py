class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        result = 0
        count = 0
        i = 0
        while i<len(nums): 
            if nums[i] == 1:
                count += 1
                if count>result:
                    result = count
            else:
                count = 0
            i+=1
        return result
