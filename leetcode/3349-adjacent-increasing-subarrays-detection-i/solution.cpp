class Solution {
public:
    bool isIncreasing(vector<int>& nums, int k, int idx) {
        int cur = INT_MIN, n = nums.size();
        for (int i = idx; i < idx + k; i++) {
            if (i >= n || cur >= nums[i]) return false;
            cur = nums[i];
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (isIncreasing(nums, k, i) && isIncreasing(nums, k, i + k)) {
                return true;
            }
        }
        return false;
    }
};
