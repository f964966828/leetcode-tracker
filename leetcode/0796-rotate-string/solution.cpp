class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string ns;
            for (int j = i; j < n; j++) ns.push_back(s[j]);
            for (int j = 0; j < i; j++) ns.push_back(s[j]);
            if (ns == goal) return true;
        }
        return false;
    }
};
