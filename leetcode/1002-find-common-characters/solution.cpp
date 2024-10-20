class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> counts(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) counts[i][ch - 'a']++;
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            int mn = INT_MAX;
            for (int j = 0; j < n; j++) mn = min(mn, counts[j][i]);
            
            string str(1, 'a' + i);
            for (int j = 0; j < mn; j++) ans.push_back(str);
        }
        return ans;
    }
};
