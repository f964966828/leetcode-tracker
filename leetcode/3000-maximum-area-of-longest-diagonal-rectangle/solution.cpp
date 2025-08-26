class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, mx = 0;
        for (auto dim : dimensions) {
            int diag = dim[0] * dim[0] + dim[1] * dim[1];
            if (diag > mx) {
                mx = diag;
                ans = dim[0] * dim[1];
            } else if (diag == mx) {
                ans = max(ans, dim[0] * dim[1]);
            }
        }
        return ans;
    }
};
