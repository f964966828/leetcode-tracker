class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - cur > k) {
                ans++;
                cur = nums[i];
            }
        }
        return ans;
    }
};
