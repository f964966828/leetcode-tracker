class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for (int i = 0; i < n + m - 1; i++) {
            int start = (i < m ? 0 : i - m + 1);
            int end = (i < n ? i : n - 1);
            int dire = 1;
            if (i % 2 == 0) {
                swap(start, end);
                dire = -1;
            }
            for (int r = start; ; r += dire) {
                ans.push_back(mat[r][i - r]);
                if (r == end) break;
            }
        }
        return ans;
    }
};
