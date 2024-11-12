bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] > b[1];
    }
}

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), cmp);
        
        int mx = 0;
        map<int, int> mp;
        for (auto& item : items) {
            if (item[1] > mx) {
                mx = item[1];
                mp[item[0]] = mx;
            }
        }
        mp[0] = 0;

        vector<int> ans;
        for (int q : queries) {
            auto iter = --mp.upper_bound(q);
            ans.push_back((*iter).second);
        }

        return ans;
    }
};
