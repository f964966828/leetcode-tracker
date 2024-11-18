class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size());
        }

        vector<int> prefix(1);
        for (int i = 0; i < abs(k) - 1; i++) code.push_back(code[i]);
        for (int i = 0; i < code.size(); i++) {
            prefix.push_back(prefix[i] + code[i]);
        }

        vector<int> ans;
        for (int i = 0; i + abs(k) <= code.size(); i++) {
            ans.push_back(prefix[i + abs(k)] - prefix[i]);
        }

        if (k > 0) {
            ans.push_back(ans[0]);
            ans.erase(ans.begin());
        } else {
            for (int i = 0; i < abs(k); i++) {
                ans.insert(ans.begin(), ans[ans.size() - 1]);
                ans.pop_back();
            }
        }

        return ans;
    }
};
