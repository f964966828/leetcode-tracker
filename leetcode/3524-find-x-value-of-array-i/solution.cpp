class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> new_dp(k, 0);
            new_dp[num % k]++;

            for (int i = 0; i < k; i++) new_dp[(i * (num % k)) % k] += dp[i];
            for (int i = 0; i < k; i++) result[i] += new_dp[i];
            dp = new_dp;
        }
        return result;
    }
};
