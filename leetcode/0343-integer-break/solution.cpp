class Solution {
public:
    int dp[60] = {0};
    int integerBreak(int n) {
        if (n == 1) {
            dp[n] = 1;
        } else if (dp[n] == 0) {
            for (int i = 1; i < n; i++) {
                int left = max(i, integerBreak(i));
                int right = max(n-i, integerBreak(n-i));
                dp[n] = max(dp[n], left * right);
            }
        }

        return dp[n];
    }
};
