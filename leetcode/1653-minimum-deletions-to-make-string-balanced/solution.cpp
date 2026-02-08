class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> prefix(n + 1), postfix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == 'b');
            postfix[n - i - 1] = postfix[n - i] + (s[n - i - 1] == 'a');
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) ans = min(ans, prefix[i] + postfix[i]);
        return ans;
    }
};
