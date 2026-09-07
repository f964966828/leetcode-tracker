class Solution {
public:
    long long maximumBooks(vector<int>& books) {      
        int n = books.size();  
        vector<long long> dp(n);

        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            while (stk.top() != -1 && books[stk.top()] >= books[i] - (i - stk.top())) stk.pop();
            int idx = stk.top();
            long long s = max(books[i] - (i - idx), 0), e = books[i];
            dp[i] = ((e + 1) * e - (s + 1) * s) / 2 + (idx == -1 ? 0 : dp[idx]); 
            stk.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};
