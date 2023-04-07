int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> bfs;
        for(int i=0; i<n; i++){
            if(grid[i][0]) bfs.push({i, 0});
            if(grid[i][m-1]) bfs.push({i, m-1});
        }

        for(int i=0; i<m; i++){
            if(grid[0][i]) bfs.push({0, i});
            if(grid[n-1][i]) bfs.push({n-1, i});
        }

        vector<vector<int>> visited(n, vector<int>(m));
        while(!bfs.empty()){
            int r = bfs.front().first;
            int c = bfs.front().second;
            bfs.pop();

            visited[r][c] = 1;
            for(int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && !visited[nr][nc]){
                    bfs.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && !visited[i][j]) ans++;
            }
        }

        return ans;
    }
};
