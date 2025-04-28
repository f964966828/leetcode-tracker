class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, ans = 0;
        int l = 0, r = 0, n = nums.size();
        while (r < n) {
            sum += nums[r++];
            while (sum * (r - l) >= k) {
                sum -= nums[l++];
            }
            ans += (r - l);
        }
        return ans;
    }
};
