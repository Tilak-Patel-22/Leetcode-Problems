class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0

        count = 1
        ans = [nums[0]]
        i = 1

        while i < len(nums):
            if nums[i] == nums[i - 1]:
                count += 1

                if count <= 2:
                    ans.append(nums[i])
            else:
                count = 1
                ans.append(nums[i])

            i += 1
        
        for i in range(len(ans)):
            nums[i] = ans[i]

        return len(ans)