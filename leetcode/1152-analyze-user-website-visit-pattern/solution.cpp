class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> user2timenweb; // (name, [time, web])
        for (int i = 0; i < username.size(); i++) {
            user2timenweb[username[i]].push_back({timestamp[i], website[i]});
        }

        set<vector<string>> all_pattern;
        unordered_map<string, set<vector<string>>> user2pattern;
        for (auto & [name, vec] : user2timenweb) {
            sort(vec.begin(), vec.end());
            
            int n = vec.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        vector<string> p = {vec[i].second, vec[j].second, vec[k].second};
                        all_pattern.insert(p);
                        user2pattern[name].insert(p);
                    }
                }
            }
        }

        int mx = 0;
        vector<string> ans;
        for (auto & p : all_pattern) {
            int count = 0;
            for (auto & [name, pattern] : user2pattern) {
                count += (pattern.find(p) != pattern.end());
            }
            if (count > mx) {
                mx = count;
                ans = p;
            }
        }

        return ans;
    }
};
