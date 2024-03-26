class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> flags(1e5 + 1, false);
        for (int num: nums) {
            if (num >= 0 && num <= 1e5) {
                flags[num] = true;
            }
        }

        for (int i = 1; i <= 1e5; i++) {
            if (!flags[i]) {
                return i;
            }
        }

        return 1e5 + 1;
    }
};
