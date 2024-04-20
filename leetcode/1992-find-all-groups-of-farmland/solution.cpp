int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& land, vector<vector<int>>& visited, int x, int y) {
        int n = land.size(), m = land[0].size();
        int x1 = x, y1 = y, x2 = x, y2 = y;

        visited[x][y] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] && !visited[nx][ny]) {
                vector<int> pos = dfs(land, visited, nx, ny);
                x1 = min(x1, pos[0]);
                y1 = min(y1, pos[1]);
                x2 = max(x2, pos[2]);
                y2 = max(y2, pos[3]);
            }
        }
        return {x1, y1, x2, y2};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> visited(n, vector<int>(m)), ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] && !visited[i][j]) {
                    ans.push_back(dfs(land, visited, i, j));
                }
            }
        }

        return ans;
    }
};
