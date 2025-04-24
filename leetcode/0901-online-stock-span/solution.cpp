class StockSpanner {
public:
    vector<int> prices;
    vector<int> results;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = prices.size() - 1;
        while (i >= 0 && prices[i] <= price) {
            i -= results[i];
        }

        int result = prices.size() - i;
        prices.push_back(price);
        results.push_back(result);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
