class Solution {
public:
    int prefix_length(string a, string b) {
        int len = 0, n = min(a.size(), b.size());
        for (int i = 0; i < n && a[i] == b[i]; i++) len++;
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> s1, s2;
        for (auto &v : arr1) s1.push_back(to_string(v));
        for (auto &v : arr2) s2.push_back(to_string(v));

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int ans = 0;
        for (auto &v1 : s1) {
            auto iter = lower_bound(s2.begin(), s2.end(), v1);
            if (iter != s2.end()) {
                string v2 = *iter;
                ans = max(ans, prefix_length(v1, v2));
            }
            if (iter != s2.begin()) {
                string v2 = *(--iter);
                ans = max(ans, prefix_length(v1, v2));
            }
        }

        return ans;
    }
};
