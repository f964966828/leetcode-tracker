class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = ("-" if numerator * denominator < 0 else "")
        numerator = abs(numerator)
        denominator = abs(denominator)

        integer = sign + str(numerator // denominator)
        numerator %= denominator
        
        decimal = ""
        index = -1
        index_map = {}
        while index == -1 and numerator != 0:
            numerator *= 10
            if numerator in index_map.keys():
                index = index_map[numerator]
            else:
                index_map[numerator] = len(decimal)
                decimal += str(numerator // denominator)
            numerator %= denominator

        if len(decimal) == 0:
            return integer
        elif index == -1:
            return integer + "." + decimal
        else:
            decimal = decimal[:index] + "(" + decimal[index:] + ")"
            return integer + "." + decimal

