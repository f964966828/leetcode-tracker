class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = nums[i], b = nums[j];
                auto iter_low = lower_bound(nums.begin(), nums.end(), b - a + 1);
                auto iter_high = upper_bound(nums.begin(), nums.end(), b + a) - 1;
                int low = max(i + 1, (int)(iter_low - nums.begin()));
                int high = min(j - 1, (int)(iter_high - nums.begin()));
                ans += max(0, high - low + 1);
            }
        }

        return ans;
    }
};
