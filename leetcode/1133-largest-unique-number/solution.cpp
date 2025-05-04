class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> counts(1001);
        for (int &num : nums) counts[num]++;

        int ans = -1;
        for (int i = 0; i <= 1000; i++) {
            if (counts[i] == 1) ans = max(ans, i);
        }

        return ans;
    }
};
