class Solution(object):
    def findNumbers(self, nums):
        return sum([1 for num in nums if 10 <= num < 100 or 1000 <= num < 10000 or num == 100000])
