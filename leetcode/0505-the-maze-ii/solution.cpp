int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        distance[start[0]][start[1]] = 1;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y, dist = distance[x][y];
                while (nx + dx[i] >= 0 && nx + dx[i] < n 
                    && ny + dy[i] >= 0 && ny + dy[i] < m
                    && !maze[nx + dx[i]][ny + dy[i]]
                ) {
                    nx += dx[i];
                    ny += dy[i];
                    dist += 1;
                }
                if (!distance[nx][ny] || distance[nx][ny] > dist) {
                    distance[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
        }

        int ans = distance[destination[0]][destination[1]] - 1;
        return (ans == 0 ? -1 : ans);
    }
};
