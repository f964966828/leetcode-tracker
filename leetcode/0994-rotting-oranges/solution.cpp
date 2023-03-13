int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m));
        vector<pair<int,int>> bfs;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    bfs.push_back({i, j});
                }
            }
        }

        int ans = 0;
        while(!bfs.empty()){
            vector<pair<int,int>> nbfs;
            for(auto p: bfs){
                int r = p.first, c = p.second;
                for(int d=0; d<4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr < 0 || nr >= n) continue;
                    if(nc < 0 || nc >= m) continue;
                    if(visited[nr][nc] || !grid[nr][nc]) continue;
                    visited[nr][nc] = 1;
                    nbfs.push_back({nr, nc});
                }
            }
            if(!nbfs.empty()) ans++;
            bfs = nbfs;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    return -1;
            }
        }

        return ans;
    }
};
