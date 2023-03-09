typedef vector<vector<int>> vvi;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    int dfs(int r, int c, vvi& visited, vvi& grid){
        int n = grid.size(), m = grid[0].size();

        int valid = !(r==0 || r==n-1 || c==0 || c==m-1);

        visited[r][c] = 1;
        for(int d=0; d<4; d++){
            int nr = r+dr[d], nc = c+dc[d];
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(visited[nr][nc] || grid[nr][nc]) continue;
            valid &= dfs(nr, nc, visited, grid);
        }

        return valid;
    }

    int closedIsland(vvi& grid) {
        int n = grid.size(), m = grid[0].size();
        vvi visited(n, vector<int>(m));
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && !grid[i][j])
                    ans += dfs(i, j, visited, grid);
                cout << i << " " << j << " " << ans << endl;
            }
        }

        return ans;
    }
};
