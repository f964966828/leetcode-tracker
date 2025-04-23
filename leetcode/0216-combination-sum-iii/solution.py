class Solution:
    def getCombinations(self, k: int, mn: int) -> List[List[int]]:
        if k == 1:
            return [[i] for i in range(mn, 10)]

        results = []
        for i in range(mn, 10):
            combs = self.getCombinations(k - 1, i + 1)
            results.extend([[i] + comb for comb in combs])

        return results

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        combs = self.getCombinations(k, 1)
        combs = [comb for comb in combs if sum(comb) == n]
        return combs

