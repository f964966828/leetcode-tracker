int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>> pq; // (-cost, row, col)
        pq.push({-grid[0][0], 0, 0});
        
        int mx = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!pq.empty()) {
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            mx = max(mx, grid[r][c]);
            if (r == n - 1 && c == m - 1) return mx;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                pq.push({-grid[nr][nc], nr, nc});
            }
        }

        return -1;
    }
};
