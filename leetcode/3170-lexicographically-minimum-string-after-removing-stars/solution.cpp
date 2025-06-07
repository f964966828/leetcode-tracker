class Solution {
public:
    string clearStars(string s) {
        int count = 0, n = s.size();
        vector<vector<int>> record(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (record[j].size()) {
                        record[j].pop_back();
                        break;
                    }
                }
                count++;
            } else {
                record[s[i] - 'a'].push_back(i);
            }
        }

        vector<pair<int, int>> vec;
        for (int i = 0; i < 26; i++) {
            for (auto &idx : record[i]) {
                vec.push_back({idx, i});
            }
        }
        sort(vec.begin(), vec.end());

        string ans;
        for (auto &[idx, val] : vec) {
            ans.push_back(val + 'a');
        }
        return ans;
    }
};
