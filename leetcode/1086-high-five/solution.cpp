class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> mp;
        for (auto e : items) {
            mp[e[0]].push_back(e[1]);
        }

        vector<vector<int>> ans;
        for (auto e : mp) {
            sort(e.second.rbegin(), e.second.rend());
            int length = min((int) e.second.size(), 5), sum = 0;
            for (int i = 0; i < length; i++) sum += e.second[i];
            ans.push_back({e.first, sum / length});
        }
        return ans;
    }
};
