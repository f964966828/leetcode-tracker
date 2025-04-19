class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for (int num : arr) mp[num]++;

        set<int> st;
        for (auto e : mp) st.insert(e.second);

        return mp.size() == st.size();
    }
};
