class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char &ch : s) mp[ch]++;

        int mx = INT_MIN, mn = INT_MAX;
        for (auto &[key, val] : mp) {
            if (val % 2) {
                mx = max(mx, val);
            } else {
                mn = min(mn, val);
            }
        }

        return mx - mn;
    }
};
