int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        
        vector<pair<int,int>> bfs;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]){
                    for(int d=0; d<4; d++){
                        int nr = i + dr[d];
                        int nc = j + dc[d];
                        if(nr < 0 || nr >= n) continue;
                        if(nc < 0 || nc >= m) continue;
                        if(!mat[nr][nc]){
                            ans[i][j] = 1;
                            bfs.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }

        while(!bfs.empty()){
            vector<pair<int,int>> nbfs;
            for(auto p: bfs){
                int r = p.first, c = p.second;
                for(int d=0; d<4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr < 0 || nr >= n) continue;
                    if(nc < 0 || nc >= m) continue;
                    if(mat[nr][nc] && !ans[nr][nc]){
                        ans[nr][nc] = ans[r][c] + 1;
                        nbfs.push_back({nr, nc});
                    }
                }
            }
            bfs = nbfs;
        }

        return ans;
    }
};
