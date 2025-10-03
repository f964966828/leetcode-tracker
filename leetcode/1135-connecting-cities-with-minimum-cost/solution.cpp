class Solution {
public:
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x);
        int gy = find(y);
        if (gx != gy) p[gy] = gx;
        return gx != gy;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<vector<int>> pq;
        for (auto & conn : connections) {
            pq.push({-conn[2], conn[0] - 1, conn[1] - 1});
        }
        for (int i = 0; i < n; i++) p.push_back(i);

        int count = 0, weight = 0;
        while (count != n && !pq.empty()) {
            auto & conn = pq.top();
            int w = -conn[0], a = conn[1], b = conn[2];
            pq.pop();
            
            if (merge(a, b)) {
                weight += w;
                count++;
            }
        }

        return (count == n - 1 ? weight : -1);
    }
};
