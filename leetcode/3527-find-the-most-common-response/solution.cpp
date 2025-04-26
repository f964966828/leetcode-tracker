class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mp;
        for (vector<string> &response : responses) {
            set<string> st;
            for (string &str : response) st.insert(str);
            for (string str : st) mp[str]++;
        }

        int mx = 0;
        string ans = "";
        for (auto &[str, count] : mp) {
            if (count > mx) {
                mx = count;
                ans = str;
            } else if (count == mx) {
                ans = min(ans, str);
            }
        }
        return ans;
    }
};
