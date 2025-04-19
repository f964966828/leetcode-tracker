class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> zero_idxs(1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero_idxs.push_back(i + 1);
        }
        zero_idxs.push_back(n + 1);
        
        int ans = 0;
        for (int i = 0; i < zero_idxs.size() - 2; i++) {
            ans = max(ans, zero_idxs[i + 2] - zero_idxs[i] - 2);
        }
        if (zero_idxs.size() == 2) ans = nums.size() - 1;

        return ans;
    }
};
