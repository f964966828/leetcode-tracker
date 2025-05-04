class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        try:
            return all([
                [words[i][j] for j in range(len(words[i]))]
                == [words[j][i] for j in range(len(words[i]))]
                for i in range(len(words))
            ])
        except:
            return False
