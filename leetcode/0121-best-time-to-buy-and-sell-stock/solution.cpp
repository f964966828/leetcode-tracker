class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, ans = INT_MIN;
        for (int num : prices) {
            mn = min(mn, num);
            ans = max(ans, num - mn);
        }
        return ans;
    }
};
