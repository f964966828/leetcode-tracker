class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (i + 1 <= n) dist[i + 1] = min(dist[i + 1], dist[i] + costs[i] + 1);
            if (i + 2 <= n) dist[i + 2] = min(dist[i + 2], dist[i] + costs[i + 1] + 4);
            if (i + 3 <= n) dist[i + 3] = min(dist[i + 3], dist[i] + costs[i + 2] + 9);
        }
        return dist[n];
    }
};
