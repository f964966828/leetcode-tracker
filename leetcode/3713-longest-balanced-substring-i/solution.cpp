class Solution {
public:
    bool check(vector<int>& count) {
        int num = -1;
        for (int & c : count) {
            if (c != 0) {
                if (num == -1) num = c;
                else if (num != c) return false;
            }
        }
        return true;
    }
    
    int longestBalanced(string s) {
        int n = s.size();
        vector<vector<int>> prefix(n + 1, vector<int>(26));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) prefix[i][j] = prefix[i - 1][j];
            prefix[i][s[i - 1] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                vector<int> count(26);
                for (int k = 0; k < 26; k++) count[k] = prefix[j][k] - prefix[i][k];
                if (check(count)) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};
