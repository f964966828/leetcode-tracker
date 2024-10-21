class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        ans = 0

        combinations = list(itertools.product([0, 1], repeat=len(s)))
        for comb in combinations:
            indices = [0]
            for i in range(len(s)):
                if comb[i] != comb[indices[-1]]:
                    indices.append(i)
            indices.append(len(s))

            strs = []
            for i in range(len(indices) - 1):
                strs.append(s[indices[i]:indices[i+1]])
            
            if len(set(strs)) == len(strs):
                ans = max(ans, len(strs))

        return ans

