class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 0) {
            return s;
        }

        int pos = -1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i]-'a' == s[i+1]-'A' || s[i]-'A'==s[i+1]-'a') {
                pos = i;
            }
        }

        if (pos == -1) {
            return s;
        } else {
            string ns = "";
            for (int i = 0; i < s.size(); i++) {
                if (i != pos && i != pos + 1) ns += s[i];
            }
            return makeGood(ns);
        }
    }
};
