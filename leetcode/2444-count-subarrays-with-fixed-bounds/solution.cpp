class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minI = -1, maxI = -1, current = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                if (nums[i] == minK) minI = i;
                if (nums[i] == maxK) maxI = i;
                ans += max(0, min(minI, maxI) - current + 1);
            } else {
                current = i + 1;
            }
        }
        return ans;
    }
};
