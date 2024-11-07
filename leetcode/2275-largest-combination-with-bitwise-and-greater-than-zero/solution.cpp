class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int count = 0, num = 1 << i;
            for (int can : candidates) {
                if (num & can) count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
