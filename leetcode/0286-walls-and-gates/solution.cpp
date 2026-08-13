int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms[0].size();
        queue<pair<int, int>> bfs;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) bfs.push({i, j});
            }
        }
        
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] == INT_MAX) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    bfs.push({nx, ny});
                }
            }
        }
    }
};
