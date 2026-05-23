class Solution:
    def minimumSwaps(self, nums: list[int]) -> int:
        n = len(nums)
        
        count = 0
        for num in nums:
            if num == 0:
                count += 1

        count2 = 0
        for num in nums[n - count:]:
            if num == 0:
                count2 += 1

        return count - count2
        
