class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = -prices[0], best_sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            best_buy = max(best_buy, best_sell - prices[i]);
            best_sell = max(best_sell, best_buy + prices[i]);
        }
        return best_sell;
    }
};
