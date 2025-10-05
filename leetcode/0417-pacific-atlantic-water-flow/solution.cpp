int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int n = heights.size(), m = heights[0].size();
        visited[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if  (heights[nr][nc] >= heights[r][c] && !visited[nr][nc]) {
                dfs(nr, nc, heights, visited); 
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> p_visited(n, vector<bool>(m, false));
        vector<vector<bool>> a_visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0) && !p_visited[i][j]) dfs(i, j, heights, p_visited);
                if ((i == n - 1 || j == m - 1) && !a_visited[i][j]) dfs(i, j, heights, a_visited);
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p_visited[i][j] && a_visited[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
