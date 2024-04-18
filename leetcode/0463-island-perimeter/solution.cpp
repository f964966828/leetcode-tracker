int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int ret = 0, n = grid.size(), m = grid[0].size();
        
        visited[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!grid[nx][ny]) {
                    ret += 1;
                } else if (!visited[nx][ny]) {
                    ret += dfs(grid, visited, nx, ny);
                }
            } else {
                ret += 1;
            }
        }

        return ret;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }

        vector<vector<int>> visited(n, vector<int>(m));
        return dfs(grid, visited, x, y);
    }
};
