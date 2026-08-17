class Solution {
public:
    vector<vector<int>> dp;
    vector<int> p_sum;

    int solver(vector<int>& stoneValue, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int m = l; m < r; m++) {
            int l_sum = p_sum[m + 1] - p_sum[l];
            int r_sum = p_sum[r + 1] - p_sum[m + 1];
            
            int ret = -1;
            if (l_sum > r_sum) {
                ret = r_sum + solver(stoneValue, m + 1, r);
            } else if (l_sum < r_sum) {
                ret = l_sum + solver(stoneValue, l, m);
            } else { // equal
                ret = l_sum + max(solver(stoneValue, l, m), solver(stoneValue, m + 1, r));
            }
            ans = max(ans, ret);
        }
        dp[l][r] = ans;
        return ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n);
        p_sum.resize(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n, -1);
            dp[i][i] = 0;
            p_sum[i + 1] = p_sum[i] + stoneValue[i];
        }
        return solver(stoneValue, 0, n - 1);
    }
};
