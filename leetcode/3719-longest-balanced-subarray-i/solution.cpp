class Solution {
public:
    int cum[2][(int) 1e5 + 5] = {0}, cnt[2] = {0};

    void add(int idx, vector<int>& nums) {
        int oddeven = nums[idx] % 2;
        if (!cum[oddeven][nums[idx]]++) cnt[oddeven]++;
    }

    void remove(int idx, vector<int>& nums) {
        int oddeven = nums[idx] % 2;
        if (!--cum[oddeven][nums[idx]]) cnt[oddeven]--;
    }

    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            add(i, nums);
            for (int j = i + 1; j < n; j++) {
                add(j, nums);
                if (cnt[0] == cnt[1]) {
                    ans = max(ans, j - i + 1);
                }
            }
            for (int j = i + 1; j < n; j++) {
                remove(j, nums);
            }
            remove(i, nums);
        }
        return ans;
    }
};
