class Solution {
public:
    int countBinarySubstrings(string s) {
        char tok = s[0];
        int prev = 0, cur = 1, ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == tok) cur++;
            else {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            tok = s[i];
        }
        ans += min(prev, cur);
        return ans;
    }
};
