class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        return sum(1 for num in nums if num == target) > len(nums) / 2
