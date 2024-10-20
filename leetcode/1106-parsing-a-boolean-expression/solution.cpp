class Solution {
public:

    void solve(string& expression, vector<pair<int, bool>>& dp, int idx) {
        if (dp[idx].first != -1) {
            return;
        } 
        
        if (expression[idx] == 't') {
            dp[idx] = {idx, true};
        } else if (expression[idx] == 'f') {
            dp[idx] = {idx, false};
        } else {
            vector<bool> flags;
            int i = idx + 2;
            while (true) {
                solve(expression, dp, i);
                flags.push_back(dp[i].second);
                i = dp[i].first;

                if (expression[i + 1] == ')') break;
                else i += 2;
            }

            bool ret;
            if (expression[idx] == '!') {
                ret = !flags[0];
            } else if (expression[idx] == '&') {
                ret = true;
                for (bool flag : flags) ret &= flag;
            } else if (expression[idx] == '|') {
                ret = false;
                for (bool flag : flags) ret |= flag;
            }
            
            dp[idx] = {i + 1, ret};
        }
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        vector<pair<int, bool>> dp(n, {-1, false});
        solve(expression, dp, 0);;
        return dp[0].second;
    }
};
