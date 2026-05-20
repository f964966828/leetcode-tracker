int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int n = room.size(), m = room[0].size();
        stack<tuple<int, int, int>> dfs; // (x, y, dir);
        vector<vector<vector<int>>> visited(n);
        for (int i = 0; i < n; i++) {
            visited[i].resize(m);
            for (int j = 0; j < m; j++) {
                visited[i][j].resize(4);
            }
        }

        dfs.push({0, 0, 0});
        while (!dfs.empty()) {
            auto [x, y, dir] = dfs.top();
            dfs.pop();

            visited[x][y][dir] = 1;
            
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = (dir + 1) % 4;
            if ((!(nx >= 0 && nx < n && ny >= 0 && ny < m) || room[nx][ny]) && !visited[x][y][nd]) {
                dfs.push({x, y, nd});
            }
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny][dir] && !room[nx][ny]) {
                dfs.push({nx, ny, dir});
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool flag = false;
                for (int k = 0; k < 4; k++) {
                    flag |= visited[i][j][k];
                }
                ans += flag;
            }
        }

        return ans;
    }
};
