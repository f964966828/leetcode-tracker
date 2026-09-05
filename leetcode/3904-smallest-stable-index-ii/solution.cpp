class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p_min(n), p_max(n);
        for (int i = 0; i < n; i++) {
            p_max[i] = (i == 0 ? nums[i] : max(p_max[i - 1], nums[i]));
            p_min[n - 1 - i] = (i == 0 ? nums[n - 1 - i] : min(p_min[n - i], nums[n - 1 - i]));
        }

        for (int i = 0; i < n; i++) {
            if (p_max[i] - p_min[i] <= k) return i;
        }
        return -1;
    }
};
