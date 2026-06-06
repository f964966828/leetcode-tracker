class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size(), b = -1;
        vector<vector<int>> intervals;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (b != -1) intervals.push_back({b, i - 1});
                b = -1;
            } else {
                if (b == -1) b = i;
            }
        }
        if (b != -1) intervals.push_back({b, n - 1});

        long long ans = 0;
        for (auto interval : intervals) {
            int b = interval[0], e = interval[1];
            if (b == 0) {
                for (int i = b; i <= e; i++) ans += nums[i];
            } else {
                int mn = INT_MAX;
                for (int i = b - 1; i <= e; i++) {
                    ans += nums[i];
                    mn = min(mn, nums[i]);
                }
                ans -= mn;
            }
        }
        return ans;
    }
};
