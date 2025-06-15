class Solution:
    def maxDiff(self, num: int) -> int:
        num = str(num)
        maxDigit = next((digit for digit in num if digit != '9'), '-1')
        minDigit = next((digit for digit in num if digit != '1' and digit != '0'), '-1')

        maxNum = ''.join(digit if digit != maxDigit else '9' for digit in num)
        minNum = ''.join(digit if digit != minDigit else ('1' if minDigit == num[0] else '0') for digit in num)

        return int(maxNum) - int(minNum)
