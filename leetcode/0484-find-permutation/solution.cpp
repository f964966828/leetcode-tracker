class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> stk;
        vector<int> ans;
        stk.push(1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') while (!stk.empty()) ans.push_back(stk.top()), stk.pop();
            stk.push(i + 2);
        }
        while (!stk.empty()) ans.push_back(stk.top()), stk.pop();
        return ans;
    }
};
