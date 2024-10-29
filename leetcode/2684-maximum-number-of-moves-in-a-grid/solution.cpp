class Solution {
public:
    int dr[3] = {-1, 0, 1};
    int dc[3] = {1, 1, 1};

    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c) {
        if (!dp[r][c]) {
            int n = grid.size(), m = grid[0].size();
            for (int i = 0; i < 3; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc < m && grid[nr][nc] > grid[r][c]) {
                    dp[r][c] = max(dp[r][c], solve(grid, dp, nr, nc) + 1);          
                }
            }
        }
        return dp[r][c];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(grid, dp, i, 0));
        }
        return ans;
    }
};
