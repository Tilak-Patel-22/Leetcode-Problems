class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        sum = 0
        freq = {0: 1}
        for i in range(len(nums)):
            sum+=nums[i]
            prev = sum - k
            
            if prev in freq:
                count += freq[prev]
            if sum in freq:
                freq[sum] += 1
            else:
                freq[sum] = 1
        return count