class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int ans = 0, i = 0, n = nums.size();
        while (i < n) {
            ans++;

            int step = nums[i];
            if (i + step >= n - 1) {
                break;
            }

            int next_i = i, mx = 0;
            for (int j = i + 1; j <= i + step; j++) {
                if (nums[j] + j >= mx) {
                    mx = nums[j] + j;
                    next_i = j;
                }
            }
            i = next_i;
        }
        return ans;
    }
};
