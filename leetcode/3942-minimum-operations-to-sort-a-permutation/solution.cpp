class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> incr(1), decr(1);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) incr.push_back(i);
            if (nums[i] > nums[i - 1]) decr.push_back(i);
        }

        int ans = INT_MAX;
        if (incr.size() == 1) {
            ans = min(ans, 0);
        } else if (incr.size() == 2 && nums[0] == nums[n - 1] + 1) {
            ans = min(ans, min(incr[1], n - incr[1] + 2));
        }

        if (decr.size() == 1) {
            ans = min(ans, 1);
        } else if (decr.size() == 2 && nums[0] + 1 == nums[n - 1]) {
            ans = min(ans, min(decr[1], n - decr[1]) + 1);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
