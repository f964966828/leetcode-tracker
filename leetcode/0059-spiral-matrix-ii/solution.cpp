int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int r=0, c=0, d=0;
        for(int i=0; i<n*n; i++){
            ans[r][c] = i+1;
            int nr = r+dr[d], nc = c+dc[d];
            if(nr>=n || nr<0 || nc>=n || nc<0 || ans[nr][nc]) d=(d+1)%4;
            r = r+dr[d];
            c = c+dc[d];
        }

        return ans;
    }
};
