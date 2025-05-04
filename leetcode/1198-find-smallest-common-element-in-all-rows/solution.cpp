class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        for (vector<int> &vec : mat) {
            for (int &num : vec) mp[num]++;
        }

        int ans = INT_MAX;
        for (auto &[key, val] : mp) {
            if (val == mat.size()) ans = min(ans, key);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
