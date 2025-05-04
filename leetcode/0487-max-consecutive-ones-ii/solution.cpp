class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, count = 0, ans = 0, n = nums.size();
        for (int r = 0; r < n; r++) {
            count += (nums[r] == 0);
            while (count > 1) count -= (nums[l++] == 0);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
