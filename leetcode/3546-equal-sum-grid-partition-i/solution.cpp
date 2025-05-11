class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rowSum(n + 1), colSum(m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i + 1] += grid[i][j];
                colSum[j + 1] += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) rowSum[i + 1] += rowSum[i];
        for (int j = 0; j < m; j++) colSum[j + 1] += colSum[j];

        for (int i = 1; i < n; i++) if (rowSum[i] * 2 == rowSum[n]) return true;
        for (int j = 1; j < m; j++) if (colSum[j] * 2 == colSum[m]) return true;
        return false;
    }
};
