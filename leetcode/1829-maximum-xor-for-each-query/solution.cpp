class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int temp = 0, mx = (1 << maximumBit) - 1;
        for (int i = 0; i < nums.size(); i++) {
            temp ^= nums[i];
            ans.push_back(mx - (temp & mx));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
