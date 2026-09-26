class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        result = [0]*len(nums)
        i = 0
        pos = 0
        neg = 1
        while i<len(nums):
            if nums[i] > 0:
                result[pos] = nums[i]
                pos+=2
            else:
                result[neg] = nums[i]
                neg+=2
            i+=1
        return result

        