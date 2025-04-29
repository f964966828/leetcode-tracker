class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int sum = 0, l = 0, n = nums.size();
        for (int r = 0; r < n; r++) {
            sum += (nums[r] == mx);
            while (sum >= k) sum -= (nums[l++] == mx);
            if (sum == k - 1) ans += l;
        }

        return ans;
    }
};
