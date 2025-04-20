int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<vector<int>> q; // row, col, dist
        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;

        int ans = INT_MAX;
        while (!q.empty()) {
            vector<int> info = q.front();
            q.pop();
            
            int x = info[0], y = info[1], dist = info[2];
            if (
                (x == 0 || x == n - 1 || y == 0 || y == m - 1) 
                && !(x == entrance[0] && y == entrance[1])
            ) {
                ans = min(ans, dist);
            }
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !visited[nx][ny]) {
                    q.push({nx, ny, dist + 1});
                    visited[nx][ny] = true;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
