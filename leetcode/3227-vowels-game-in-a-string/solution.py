class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any([ch in s for ch in "aeiou"])
