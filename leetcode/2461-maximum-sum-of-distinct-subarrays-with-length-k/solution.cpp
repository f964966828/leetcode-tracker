class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int count = 0;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            count += (mp[nums[i]]++ == 1);
        }
        
        long long ans = 0;
        if (count == 0) ans = max(ans, sum);
        for (int i = k; i < nums.size(); i++) {
            sum += (nums[i] - nums[i - k]);
            count += (mp[nums[i]]++ == 1);
            count -= (--mp[nums[i - k]] == 1);
            if (count == 0) ans = max(ans, sum);
        }

        return ans;
    }
};
