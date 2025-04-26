class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        vector<vector<pair<int, int>>> adj_list(n); // adj_list[from] = [(to, factor)]
        for (vector<int> &conv : conversions) {
            adj_list[conv[0]].push_back({conv[1], conv[2]});
        }
        
        vector<int> units(n);
        stack<int> stk;
        stk.push(0);
        units[0] = 1;
        while (!stk.empty()) {
            int from = stk.top(); stk.pop();
            for (auto &[to, factor] : adj_list[from]) {
                units[to] = ((long long)units[from] * factor) % mod;
                stk.push(to);
            }
        }

        return units;
    }
};
