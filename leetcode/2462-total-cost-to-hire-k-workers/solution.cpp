using pii = pair<int, int>;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;

        // (cost, source)
        // source - 0: first, 1: last
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = costs.size(), l = 0, r = n - 1;
        for (int i = 0; i < candidates && l <= r; i++) pq.push({costs[l++], 0});
        for (int i = 0; i < candidates && l <= r; i++) pq.push({costs[r--], 1});

        long long sum = 0;
        while (k--) {
            sum += pq.top().first;
            int source = pq.top().second;
            pq.pop();

            if (!source && l <= r) {
                pq.push({costs[l++], 0});
            } else if (source && l <= r) {
                pq.push({costs[r--], 1});
            }
        }

        return sum;
    }
};
