class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> diffs;
        for (string word : words) {
            vector<int> diff;
            for (int i = 0; i < word.size() - 1; i++) {
                diff.push_back(word[i + 1] - word[i]);
            }
            diffs.push_back(diff);
        }

        map<vector<int>, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[diffs[i]].push_back(i);

        for (auto &e: mp) {
            if (e.second.size() == 1) {
                return words[e.second[0]];
            }
        }

        return "";
    }
};
