class Solution:
    def romanToInt(self, s: str) -> int:
        mp = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        ans = 0
        for ch in s[::-1]:
            n = mp[ch]
            if ans >= n*5:
                ans -= n
            else:
                ans += n
        
        return ans;
