class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, mn = INT_MAX, idx = -1, n = gas.size();
        for (int i = 0; i < n; i++) {
            sum += (gas[i] - cost[i]);
            if (sum < mn) {
                mn = sum;
                idx = (i + 1) % n;
            }
        }

        int t_gas = 0, t_cost = 0;
        for (int i = 0; i < n; i++) {
            t_gas += gas[(i + idx) % n];
            t_cost += cost[(i + idx) % n];
            if (t_gas < t_cost) return -1;
        }

        return idx;
    }
};
