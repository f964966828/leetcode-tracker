class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {0};
        for (char ch : s) {
            int now = ch - 'a', from = max(0, now - k), to = min(25, now + k), mx = 0;
            for (int i = from; i <= to; i++) {
                mx = max(mx, dp[i] + 1);
            }
            dp[now] = mx;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
