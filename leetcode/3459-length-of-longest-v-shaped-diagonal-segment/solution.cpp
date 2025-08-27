int dr[] = {-1, 1, 1, -1};
int dc[] = {1, 1, -1, -1};

class Solution {
public:
    int n;
    int m;
    vector<vector<int>> grid;
    int dist[500][500][4] = {0}; // (r, c, d);
    
    int search(int r, int c, int d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) return 1;
        if (grid[nr][nc] != (!grid[r][c]) * 2) return 1;
        if (dist[nr][nc][d]) return dist[nr][nc][d] + 1;
        return dist[r][c][d] = search(nr, nc, d) + 1;
    }

    bool check(int r, int c, int d) {
        int l = dist[r][c][d];
        int nr = r + dr[d] * l;
        int nc = c + dc[d] * l;
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) return false;
        return ((grid[r][c] == 0) ^ (l % 2)) && grid[nr][nc] == 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    ans = max(ans, 1);
                    continue;
                }
                for (int d = 0; d < 4; d++) dist[r][c][d] = search(r, c, d);
                for (int d = 0; d < 4; d++) {
                    int nd = (d + 1) % 4;
                    if (check(r, c, nd)) {
                        ans = max(ans, dist[r][c][d] + dist[r][c][nd]);
                    }
                }
            }
        }
        return ans;
    }
};
