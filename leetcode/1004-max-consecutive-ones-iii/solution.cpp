class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p_sum(1);
        for (int i = 0; i < n; i++) {
            p_sum.push_back(p_sum[i] + (nums[i] == 0));
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int target = p_sum[i + 1] - k;
            auto iter = lower_bound(p_sum.begin(), p_sum.end(), target);
            ans = max(ans, i - int(iter - p_sum.begin()) + 1);
        }

        return ans;
    }
};
