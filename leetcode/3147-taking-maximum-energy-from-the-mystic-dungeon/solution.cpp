class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        for (int i = 0; i < k; i++) dp[i] = energy[i];
        for (int i = k; i < n; i++) dp[i] = max(dp[i - k], 0) + energy[i];
        
        int ans = -1e9;
        for (int i = n - k; i < n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};
