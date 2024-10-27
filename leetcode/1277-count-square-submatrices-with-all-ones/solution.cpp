class Solution {
public:
    bool check_square(vector<vector<int>>& matrix, int r, int c, int sz) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = r; i < r + sz; i++) {
            for (int j = c; j < c + sz; j++) {
                if (i >= n || j >= m || matrix[i][j] == 0) return false;
            }
        }
        return true;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int sz = 1; sz <= min(n, m); sz++) {
            for (int r = 0; r < n; r++) {
               for (int c = 0; c < m; c++) {
                    ans += check_square(matrix, r, c, sz);
                }
            }
        }
        return ans;
    }
};
