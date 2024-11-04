class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> prefix(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) prefix[i + 1][j] = prefix[i][j];
            prefix[i + 1][s[i] - 'a']++;
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int ret = 0;
            for (int i = 0; i < 26; i++) {
                int count = prefix[q[1] + 1][i] - prefix[q[0]][i];
                ret += count * (count + 1) / 2;
            }
            ans.push_back(ret);
        }

        return ans;
    }
};
