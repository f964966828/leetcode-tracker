class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [] if n % 2 == 0 else [0]
        ans.extend([i + 1 for i in range(n // 2)])
        ans.extend([-i - 1 for i in range(n // 2)])
        return ans

