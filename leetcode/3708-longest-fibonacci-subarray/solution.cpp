class Solution {
public:
    int checkFibo(vector<int>& nums, int idx) {
        int n = nums.size();
        while (idx < n - 2 && nums[idx] + nums[idx + 1] == nums[idx + 2]) idx++;
        return idx;
    }
    
    int longestSubarray(vector<int>& nums) {
        int cur = 0, n = nums.size(), mx = 0;
        while (cur != n - 1) {
            int next = checkFibo(nums, cur);
            mx = max(mx, next - cur + 2);
            if (cur == next) cur = next + 1;
            else cur = next;
        }
        return mx;
    }
};
