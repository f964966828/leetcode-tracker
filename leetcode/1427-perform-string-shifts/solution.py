class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        n = len(s)
        for dire, amount in shift:
            if dire == 1:
                amount = n - amount % n
            else:
                amount = amount % n

            s = s[amount:] + s[:amount]
        return s
