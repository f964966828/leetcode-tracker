class Solution {
public:
    int solve(int l, int r, vector<int>& values, vector<vector<int>>& dp) {
        if (dp[l][r] != INT_MAX) return dp[l][r];

        for (int i = l + 1; i < r; i++) {
            int cost = values[l] * values[r] * values[i];
            cost += solve(l, i, values, dp);
            cost += solve(i, r, values, dp);
            dp[l][r] = min(dp[l][r], cost);
        }

        return dp[l][r];
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = 0;
        return solve(0, n - 1, values, dp);
    }
};
