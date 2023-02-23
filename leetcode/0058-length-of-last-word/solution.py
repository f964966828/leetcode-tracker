class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        toks = s.split(' ')
        for tok in toks:
            if tok != '':
                ans = len(tok)

        return ans
