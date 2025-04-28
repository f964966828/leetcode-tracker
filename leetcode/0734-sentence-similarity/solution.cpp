class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_map<string, set<string>> mp;
        for (auto &pair : similarPairs) {
            string a = pair[0], b = pair[1];
            mp[a].insert(b);
            mp[b].insert(a);
        }

        if (sentence1.size() != sentence2.size()) {
            return false;
        } else {
            for (int i = 0; i < sentence1.size(); i++) {
                string str1 = sentence1[i], str2 = sentence2[i];
                if (str1 != str2 && mp[str1].find(str2) == mp[str1].end()) {
                    return false;
                }
            }
        }

        return true;
    }
};
