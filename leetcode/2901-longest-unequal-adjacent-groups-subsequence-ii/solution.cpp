class Solution {
public:
    bool valid(string &a, string &b) {
        if (a.size() != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += (a[i] != b[i]);
        }
        return (diff == 1);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 0), parents(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (valid(words[i], words[j]) && groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parents[i] = j;
                }
            }
        }
        
        int mx = INT_MIN, idx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }

        vector<string> ans;
        while (idx != -1) {
            ans.push_back(words[idx]);
            idx = parents[idx];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
