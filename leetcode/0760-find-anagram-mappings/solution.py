class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {num : i for i, num in enumerate(nums2)}
        return [mp[num] for num in nums1]

