class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans(n / 3), empty;
        for (int i = 0; i < n; i++) {
            if (i % 3 == 2 && nums[i] - nums[i - 2] > k) {
                return empty;
            }
            ans[i / 3].push_back(nums[i]);
        }
        return ans;
    }
};
