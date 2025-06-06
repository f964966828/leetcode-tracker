class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> prefixMin(n, 26);
        prefixMin[n - 1] = s[n - 1] - 'a';
        for (int i = n - 2; i >= 0; i--) {
            prefixMin[i] = min(prefixMin[i + 1], s[i] - 'a');
        }

        string ans;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() <= prefixMin[i]) {
                ans.push_back(stk.top() + 'a');
                stk.pop();
            }
            stk.push(s[i] - 'a');
        }
        while (!stk.empty()) {
            ans.push_back(stk.top() + 'a');
            stk.pop();
        }

        return ans;
    }
};
