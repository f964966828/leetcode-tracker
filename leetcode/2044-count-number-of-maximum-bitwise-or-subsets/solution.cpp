class Solution {
public:
    void solve(vector<int>& nums, int i, int current, int target, int& ans) {
        if (i == nums.size()) {
            if (current == target) ans++;
        } else {
            solve(nums, i + 1, current, target, ans);
            solve(nums, i + 1, current | nums[i], target, ans);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        for (int num : nums) mx |= num;

        int ans = 0;
        solve(nums, 0, 0, mx, ans);

        return ans;
    }
};
