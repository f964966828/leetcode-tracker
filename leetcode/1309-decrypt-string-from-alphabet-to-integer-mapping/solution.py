class Solution:
    def freqAlphabets(self, s: str) -> str:
        for i in range(10, 27):
            s = s.replace(str(i)+'#', chr(96+i))
        for i in range(1, 10):
            s = s.replace(str(i), chr(96+i))

        return s
