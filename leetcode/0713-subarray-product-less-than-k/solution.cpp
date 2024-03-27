class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, pos = 0, pro = 1;
        for (int i = 0; i < nums.size(); i++) {
            pro *= nums[i];
            while (pos < i && pro >= k) {
                pro /= nums[pos++];
            }
            ans += (i - pos);
            if (nums[i] < k) ans++;
        }
        return ans;
    }
};
