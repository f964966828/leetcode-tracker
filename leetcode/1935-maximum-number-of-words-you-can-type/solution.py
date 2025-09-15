class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        return sum(0 if any(ch in brokenLetters for ch in word) else 1 for word in text.split())
