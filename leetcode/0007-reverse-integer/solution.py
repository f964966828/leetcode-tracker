class Solution:
    def reverse(self, x: int) -> int:
        s = str(x)
        if s[0] == '-':
            num = int(s[1:][::-1])
            return -1 * num if num < pow(2, 31) else 0
        else:
            num = int(s[::-1])
            return num if num < pow(2, 31) else 0
