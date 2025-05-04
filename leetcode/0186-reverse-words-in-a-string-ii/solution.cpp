class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int l = 0, n = s.size();
        for (int r = 0; r < n; r++) {
            if (s[r] == ' ') {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
        }
        reverse(s.begin() + l, s.begin() + n);
    }
};
