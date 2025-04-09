class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int flag[105] = {0};
        for (int num : nums) flag[num] = 1;
        
        for (int i = 1; i < k; i++) {
            if (flag[i]) return -1;
        }

        int ans = 0;
        for (int i = k + 1; i <= 100; i++) {
            if (flag[i]) ans++;
        }

        return ans;
    }
};
