int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    void solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dist) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> bfs;
        bfs.push({r, c});

        while (!bfs.empty()) {
            int r = bfs.front().first, c = bfs.front().second; bfs.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    bfs.push({nr, nc});
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dist_all;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
                    dist[i][j] = 0;
                    solve(i, j, grid, dist);
                    dist_all.push_back(dist);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int sum = 0, valid = 1;
                    for (int k = 0; k < dist_all.size(); k++) {
                        valid = (dist_all[k][i][j] == INT_MAX ? 0 : valid);
                        if (valid) sum += dist_all[k][i][j];
                    }
                    if (valid) ans = min(ans, sum);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
