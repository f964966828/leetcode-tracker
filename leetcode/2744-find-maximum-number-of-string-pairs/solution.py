class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        ans = 0
        for word1 in words:
            for word2 in words:
                if word1 != word2 and word1 == word2[::-1]:
                    ans += 1
        return ans // 2
