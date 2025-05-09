class Solution {
public:
    const int mod = 1e9 + 7;
    long long fastPow(long long base, long long pow) {
        long long ret = 1;
        while (pow) {
            if (pow & 1) ret = ret * base % mod;
            base = base * base % mod;
            pow >>= 1;
        }
        return ret;
    }
    
    int countBalancedPermutations(string num) {
        int sum = 0, n = num.size();
        vector<int> counts(10);
        for (char &ch : num) {
            int val = ch - '0';
            counts[val]++;
            sum += val;
        }

        if (sum % 2 == 1) {
            return 0;
        }

        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invFact[n] = fastPow(fact[n], mod - 2);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % mod;

        vector<vector<long long>> dp(sum / 2 + 1, vector<long long>(n / 2 + 1));
        dp[0][0] = 1;
        for (char &ch : num) {
            int val = ch - '0';
            for (int i = sum / 2; i >= val; i--) {
                for (int j = n / 2; j > 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - val][j - 1]) % mod;
                }
            }
        }

        long long ans = dp[sum / 2][n / 2];
        ans = ans * fact[n / 2] % mod * fact[n - n / 2] % mod;
        for (int &c : counts) ans = ans * invFact[c] % mod;

        return ans;
    }
};
