class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n*m != r*c) return mat;
        
        vector<vector<int>> ans;
        vector<int> row;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row.push_back(mat[i][j]);
                if(row.size() == n*m/r){
                    ans.push_back(row);
                    row.clear();
                }
            }
        }

        return ans;
    }
};
