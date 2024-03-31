class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> counts(256);
        int pos = 0, dist = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            dist += (counts[s[i]]++ == 0);
            while (dist > k) {
                dist -= (--counts[s[pos++]] == 0);
            }
            ans = max(ans, i - pos + 1);
        }
        return ans;
    }
};
