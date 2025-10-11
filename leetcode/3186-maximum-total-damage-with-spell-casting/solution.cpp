class Solution {
public:
    long long solve(int idx, vector<long long>& dp, vector<pair<int, int>>& data) {
        if (idx >= dp.size()) return 0;
        if (dp[idx]) return dp[idx];
        
        int j = idx, val = data[idx].first;
        while (j < dp.size() && data[j].first <= val + 2) j++;
        long long take = (long long) data[idx].first * data[idx].second + solve(j, dp, data);
        return dp[idx] = max(take, solve(idx + 1, dp, data));
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        
        int cur = power[0], count = 1;
        vector<pair<int, int>> data;
        for (int i = 1; i < power.size(); i++) {
            if (power[i] == cur) {
                count++;
            } else {
                data.push_back({cur, count});
                cur = power[i];
                count = 1;
            }
        }
        data.push_back({cur, count});

        int n = data.size();
        vector<long long> dp(n);
        return solve(0, dp, data);
    }
};
