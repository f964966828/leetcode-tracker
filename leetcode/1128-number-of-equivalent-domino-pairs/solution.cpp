class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        unordered_map<int, int> mp;
        for (int i = 0; i < dom.size(); i++) {
            if (dom[i][0] > dom[i][1]) swap(dom[i][0], dom[i][1]);
            mp[dom[i][0] * 10 + dom[i][1]]++;
        }

        int ans = 0;
        for (auto &[key, val] : mp) ans += val * (val - 1) / 2;

        return ans;
    }
};
