class Solution:
    def maximum69Number (self, num: int) -> int:
        s = list(str(num))
        idx = str(num).find('6')
        if idx != -1:
            s[idx] = '9'
        return int("".join(s))
