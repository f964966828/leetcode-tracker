class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        array1 = [int(num) for num in version1.split('.')]
        array2 = [int(num) for num in version2.split('.')]

        n = max(len(array1), len(array2))
        array1 = array1 + [0] * (n - len(array1))
        array2 = array2 + [0] * (n - len(array2))
        for num1, num2 in zip(array1, array2):
            if num1 < num2:
                return -1
            elif num1 > num2:
                return 1

        return 0

