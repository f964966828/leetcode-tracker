class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), pmin[n];
        pmin[0] = 1e9;
        for(int i=1; i<n; i++) pmin[i] = min(pmin[i-1], prices[i-1]);
        
        int ans = 0;
        for(int i=1; i<n; i++) ans = max(ans, prices[i] - pmin[i]);
        return ans;
    }
};
