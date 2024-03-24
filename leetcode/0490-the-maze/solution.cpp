int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    void dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y) {
        int n = maze.size(), m = maze[0].size();
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x;
            int ny = y;
            while (nx + dx[i] >= 0 && nx + dx[i] < n 
                && ny + dy[i] >= 0 && ny + dy[i] < m
                && !maze[nx + dx[i]][ny + dy[i]]) {
                nx += dx[i];
                ny += dy[i];
            }
            if (!visited[nx][ny]) {
                dfs(maze, visited, nx, ny);
            }
        }
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(maze, visited, start[0], start[1]);
        return visited[destination[0]][destination[1]];
    }
};
