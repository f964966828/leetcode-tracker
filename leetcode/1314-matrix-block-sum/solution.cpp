class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> p(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+mat[i-1][j-1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int r1=max(0, i-k), c1=max(0, j-k), r2=min(n, i+k+1), c2=min(m, j+k+1);
                ans[i][j] = p[r2][c2]-p[r1][c2]-p[r2][c1]+p[r1][c1];
            }
        }

        return ans;
    }
};
