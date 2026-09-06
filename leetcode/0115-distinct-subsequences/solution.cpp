class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<unsigned long long> dp(n + 1);
        dp[0] = 1;

        for (char ch : s) {
            for (int i = n - 1; i >= 0; i--) {
                if (ch == t[i]) {
                    dp[i + 1] += dp[i];
                }
            }
        }

        return dp[n];
    }
};
