class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
        return not (('1' in s) ^ ('1' in target))

'''
a  b or xor
0  0  0  0
0  1  1  1
1  0  1  1
1  1  1  0

s  t  ans
0  0  1
0  1  0
1  0  0
1  1  1
'''
