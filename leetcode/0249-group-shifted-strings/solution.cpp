class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (string &str : strings) {
            int offset = 26 - str[0] - 'a';
            string key(str);
            for (char &ch : key) ch = (ch - 'a' + offset) % 26 + 'a';
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &[key, vec] : mp) ans.push_back(vec);

        return ans;
    }
};
