class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, pos = 0, n = nums.size();
        map<int, int> counts;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            counts[num]++;
            if (counts[num] > k) {
                while (pos < n && nums[pos] != num) {
                    counts[nums[pos]]--;
                    pos++;
                }
                counts[num]--;
                pos++;
            }
            ans = max(ans, i - pos + 1);
        }
        return ans;
    }
};
