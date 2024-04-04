class Solution {
public:
    int maxDepth(string s) {
        string ns = "";
        int count = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (count++ != 0) {
                    ns += s[i];
                }
            } else if (s[i] == ')') {
                if (--count == 0) {
                    ans = max(ans, maxDepth(ns) + 1);
                    ns.clear();
                } else {
                    ns += s[i];
                }
            } else {
                ns += s[i];
            }
        }
        return ans;
    }
};
