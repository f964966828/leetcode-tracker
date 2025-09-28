class Solution {
public:
    const int mod = 1e9 + 7;
    
    void up(vector<int>& vec) {
        int d = vec.size(), sum = 0;
        for (auto & num : vec) sum = (sum + num) % mod;
        for (int i = d - 1; i >= 0; i--) {
            sum = (sum - vec[i] + mod) % mod;
            vec[i] = sum;
        }
    }

    void down(vector<int>& vec) {
        int d = vec.size(), sum = 0;
        for (auto & num : vec) sum = (sum + num) % mod;
        for (int i = 0; i < d; i++) {
            sum = (sum - vec[i] + mod) % mod;
            vec[i] = sum;
        }
    }
    
    int zigZagArrays(int n, int l, int r) {
        int d = r - l + 1;
        vector<int> dp(d);
        for (int i = 0; i < d; i++) dp[i] = 1;
        while (--n) {
            if (n % 2) {
                up(dp);
            } else {
                down(dp);
            }
        }

        int ans = 0;
        for (int & num : dp) ans = (ans + num) % mod;
        return (ans * 2) % mod;
    }
};
