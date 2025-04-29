class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<unordered_map<int, int>> mp(m);
        for (int i = 0; i < m; i++) for (int j = 0; j < k; j++) if (mat1[i][j]) mp[i][j] = mat1[i][j];

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (auto &[col, val] : mp[i]) sum += val * mat2[col][j];
                ret[i][j] = sum;
            }
        }

        return ret;
    }
};
