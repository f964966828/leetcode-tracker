class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, n = nums.size(), r = 0;
        for (int l = 0; l < n; l++) {
            while (r != n && nums[r] <= (long long) nums[l] * k) r++;
            int count = n - (r - l);
            ans = min(ans, count);
        }
        return ans;
    }
};
