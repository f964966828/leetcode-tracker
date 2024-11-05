class Solution {
public:
    int minChanges(string s) {
        vector<int> counts;
        char ch = s[0];
        int n = s.size(), count = 1;
        for (int i = 1; i < n; i++) {
            if (ch != s[i]) {
                counts.push_back(count);
                ch = s[i];
                count = 1;
            } else {
                count++;
            }
            
            if (i == n - 1) {
                counts.push_back(count);
            }
        }

        int ans = 0;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] % 2) {
                ans++;
                if (i != counts.size() - 1) {
                    counts[i + 1]++;
                }
            }
        }

        return ans;
    }
};
