class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        vector<int> dp(sum + 1);
        for (int num : nums) {
            for (int i = sum; i >= 0; i--) {
                if (dp[i]) dp[i + num] = 1;
            }
            dp[num] = 1;
        }

        return sum % 2 == 0 && dp[sum / 2];
    }
};
