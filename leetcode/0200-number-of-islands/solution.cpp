int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int n = grid.size(), m = grid[0].size();
        visited[r][c] = 1;
        for(int d=0; d<4; d++){
            int nr = r+dr[d], nc = c+dc[d];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]=='1' && !visited[nr][nc])
                dfs(nr, nc, visited, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        
        int ans = 0;
        for(int r=0; r<n; r++)
            for(int c=0; c<m; c++)
                if(grid[r][c]=='1' && !visited[r][c]){
                    dfs(r, c, visited, grid);
                    ans++;
                }

        return ans;
    }
};
