class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // 0: buy, 1: sell
        int max_buy = -prices[0], max_sell = 0;
        for (int i = 1; i < n; i++) {
            int buy = max_sell - prices[i];
            int sell = max_buy + prices[i] - fee;
            max_buy = max(max_buy, buy);
            max_sell = max(max_sell, sell);
        }

        return max_sell;
    }
};
