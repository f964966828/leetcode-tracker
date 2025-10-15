class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<vector<int>> itvs;
        int cur = nums[0], start = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= cur) {
                itvs.push_back({start, i - 1});
                start = i;
            }
            cur = nums[i];
        }
        itvs.push_back({start, n - 1});

        int ans = 0;
        for (int i = 0; i < itvs.size(); i++) {
            ans = max(ans, (itvs[i][1] - itvs[i][0] + 1) / 2);
            if (i < itvs.size() - 1 && itvs[i][1] + 1 == itvs[i + 1][0]) {
                int cur = itvs[i][1] - itvs[i][0] + 1;
                int next = itvs[i + 1][1] - itvs[i + 1][0] + 1;
                ans = max(ans, min(cur, next));
            }
        }
        return ans;
    }
};
