class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        n = len(picture)
        m = len(picture[0])
        rowCounts = [sum(1 for c in range(m) if picture[r][c] == 'B') for r in range(n)]
        colCounts = [sum(1 for r in range(n) if picture[r][c] == 'B') for c in range(m)]
        return sum(
            sum(1 for c in range(m) if colCounts[c] == 1 and picture[r][c] == 'B') 
            for r in range(n) if rowCounts[r] == 1
        )

