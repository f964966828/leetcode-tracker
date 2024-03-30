class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool valid = true;
                int counts[26] = {0};
                for (int k = i; k <= j; k++) {
                    counts[s[k] - 'a']++;
                    if (counts[s[k] - 'a'] > 2) {
                        valid = false;
                    }
                }
                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
