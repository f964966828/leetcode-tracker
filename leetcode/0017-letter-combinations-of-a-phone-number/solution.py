class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mp = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }

        ans = [""]
        for d in digits:
            new_ans = list()
            for a in ans:
                for ch in mp[d]:
                    new_ans.append(a + ch)
            ans = new_ans

        if len(ans) == 1:
            ans = []

        return ans
