class Solution {
public:
    vector<int> p_sum;
    vector<vector<int>> dp;

    int solver(vector<int>& piles, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];

        int sum = p_sum[r + 1] - p_sum[l];
        int l_ret = piles[l] + (sum - solver(piles, l + 1, r));
        int r_ret = piles[r] + (sum - solver(piles, l, r - 1));
        
        dp[l][r] = max(l_ret, r_ret);
        return dp[l][r];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n);
        p_sum.resize(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n, -1);
            dp[i][i] = piles[i];
            p_sum[i + 1] = p_sum[i] + piles[i];
        }
        return solver(piles, 0, n - 1) * 2 > p_sum[n];
    }
};
