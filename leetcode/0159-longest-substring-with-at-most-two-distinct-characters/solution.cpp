class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> counts(256);
        int l = 0, count = 0, ans = 0, n = s.size();
        for (int r = 0; r < n; r++) {
            count += (counts[s[r]]++ == 0);
            while (count > 2) count -= (--counts[s[l++]] == 0);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
