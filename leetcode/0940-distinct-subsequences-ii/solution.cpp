class Solution {
public:
    const int mod = 1e9 + 7;

    int distinctSubseqII(string s) {
        long long ans = 0;
        vector<long long> dp(26, 1);
        for (char ch : s) {
            int idx = ch - 'a';
            ans = (ans + dp[idx]) % mod;
            for (int i = 0; i < 26; i++) {
                if (i != idx) dp[i] = (dp[i] + dp[idx]) % mod;
            }
        }
        return ans;
    }
};
