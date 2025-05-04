class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int n = pow(2, N), base = n * n / 4;
        vector<vector<int>> matrix(n, vector<int>(n));
        if (N == 0) {
            return matrix;
        } else {
            vector<vector<int>> subMatrix = specialGrid(N - 1);
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    matrix[i][j] = base * 3 + subMatrix[i][j];
                    matrix[i + n / 2][j] = base * 2 + subMatrix[i][j];
                    matrix[i + n / 2][j + n / 2] = base * 1 + subMatrix[i][j];
                    matrix[i][j + n / 2] = subMatrix[i][j];
                }
            }
            return matrix;
        }
    }
};
