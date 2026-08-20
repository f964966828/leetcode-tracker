class NumMatrix {
public:
    int n;
    int m;
    vector<vector<int>> matrix;
    vector<vector<int>> p_sum;

    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        n = matrix.size();
        m = matrix[0].size();

        p_sum.resize(n);
        for (int i = 0; i < n; i++) {
            p_sum[i].push_back(0);
            for (int j = 0; j < m; j++) {
                p_sum[i].push_back(p_sum[i][j] + matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) { // O(n)
        int diff = val - matrix[row][col];
        for (int i = col + 1; i <= m; i++) {
            p_sum[row][i] += diff;
        }
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { // O(n)
        int ret = 0;
        for (int i = row1; i <= row2; i++) {
            ret += p_sum[i][col2 + 1] - p_sum[i][col1];
        }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
