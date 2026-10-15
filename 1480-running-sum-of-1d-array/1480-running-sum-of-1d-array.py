class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        ans = []
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            ans.append(sum)
            i+=1
        return ans