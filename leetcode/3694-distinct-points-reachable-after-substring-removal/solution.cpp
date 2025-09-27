class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int> pre_x(n + 1), pre_y(n + 1);
        for (int i = 0; i < n; i++) {
            int dx = (s[i] == 'L' || s[i] == 'R' ? (s[i] == 'L' ? -1 : 1) : 0);
            int dy = (s[i] == 'U' || s[i] == 'D' ? (s[i] == 'U' ? 1 : -1) : 0);
            pre_x[i + 1] = pre_x[i] + dx;
            pre_y[i + 1] = pre_y[i] + dy;
        }

        set<pair<int, int>> st;
        for (int i = 0; i <= n - k; i++) {
            int dx = pre_x[i] + pre_x[n] - pre_x[i + k];
            int dy = pre_y[i] + pre_y[n] - pre_y[i + k];
            st.insert({dx, dy});
        }

        return st.size();
    }
};
