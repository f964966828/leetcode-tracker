def parseNumber(num: str):
    num = num.replace('+', ' ')
    num = num.replace('i', '')
    r, i = num.split(' ')
    return int(r), int(i) 

class Solution:  
    
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        r1, i1 = parseNumber(num1)
        r2, i2 = parseNumber(num2)

        r = r1*r2 - i1*i2
        i = r1*i2 + r2*i1

        return f"{r}+{i}i"
