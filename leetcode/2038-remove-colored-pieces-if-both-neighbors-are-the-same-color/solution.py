from itertools import groupby
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        count_a = count_b = 0
        results = [''.join(g) for _, g in groupby(colors)]
        for result in results:
            if result[0] == 'A':
                count_a += max(0, len(result)-2)
            elif result[0] == 'B':
                count_b += max(0, len(result)-2)
        
        return count_a > count_b

