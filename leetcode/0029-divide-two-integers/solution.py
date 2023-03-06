import numpy as np
import math

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ret = dividend / divisor
        if ret < 0:
            ret = math.ceil(ret)
        else:
            ret = math.floor(ret)

        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1
        return np.clip(ret, INT_MIN, INT_MAX)

