class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> p_sum(1, 0);
        for (int i = 0; i < n; i++) {
            p_sum.push_back(p_sum[i] + (possible[i] == 1 ? 1 : -1));
        }
        
        for (int i = 1; i < n; i++) {
            if (p_sum[i] > p_sum[n] - p_sum[i]) {
                return i;
            }
        }
        
        return -1;
    }
};
