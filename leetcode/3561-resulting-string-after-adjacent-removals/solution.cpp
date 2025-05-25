class Solution {
public:
    string resultingString(string s) {
        stack<int> stk;
        for (char &ch : s) {
            int val = ch - 'a';
            if (!stk.empty() && abs(val - stk.top()) % 24 == 1) {
                stk.pop();
            } else {
                stk.push(val);
            }
        }

        string ans;
        while (!stk.empty()) {
            ans.push_back(stk.top() + 'a');
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
