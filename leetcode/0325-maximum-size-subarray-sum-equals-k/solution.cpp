using LL = long long;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<LL, int> mp;
        mp[0] = 0;

        LL sum = 0;
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            LL target = sum - k;
            auto iter = mp.find(target);
            if (iter != mp.end()) ans = max(ans, i - iter->second);
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return ans;
    }
};
