class Solution:
    def confusingNumber(self, n: int) -> bool:
        mp = {
            0: 0,
            1: 1,
            6: 9,
            8: 8,
            9: 6,
        }

        temp = n
        num = 0
        while temp != 0:
            if temp % 10 in [2, 3, 4, 5, 7]:
                return False
            else:
                num = num * 10 + mp[temp % 10]
            temp //= 10

        return n != num

