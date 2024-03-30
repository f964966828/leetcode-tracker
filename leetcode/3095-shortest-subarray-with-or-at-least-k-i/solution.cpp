class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int ret = 0;
                for (int m = i; m <= j; m++) {
                    ret |= nums[m];
                }
                if (ret >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};
