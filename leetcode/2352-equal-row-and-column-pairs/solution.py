class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        row_strings = [str([grid[i][j] for j in range(m)]) for i in range(n)]
        col_strings = [str([grid[j][i] for j in range(n)]) for i in range(m)]

        row_map = {}
        for string in row_strings:
            if string not in row_map.keys():
                row_map[string] = 0
            row_map[string] += 1

        ans = 0
        for string in col_strings:
            if string in row_map.keys():
                ans += row_map[string]

        return ans

