class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        nums = set([1, 2, 3, 4, 5, 6])
        for top, bot in zip(tops, bottoms):
            nums = nums & set([top, bot])

        ans = 1e5
        for num in nums:
            ans = min(ans, sum(1 for top in tops if num != top))
            ans = min(ans, sum(1 for bot in bottoms if num != bot))

        return ans if ans != 1e5 else -1

