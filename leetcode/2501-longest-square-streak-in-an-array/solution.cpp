class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            long long target = nums[i];
            while (true) {
                auto iter = lower_bound(nums.begin(), nums.end(), target);
                if (iter != nums.end() && *iter == target) count++;
                else break;
                target = target * target;
            }
            if (count != 1) ans = max(ans, count);
        }
        return ans;
    }
};
