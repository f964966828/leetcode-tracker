class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] % modulo == k);
        }

        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = n; i >= 0; i--) {
            ans += mp[(prefix[i] + k) % modulo];
            mp[prefix[i] % modulo]++;
        }

        return ans;
    }
};
