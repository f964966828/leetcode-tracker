class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 1, current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= current) {
                ans++;
                current = nums[i];
            }
        }
        return ans;
    }
};
