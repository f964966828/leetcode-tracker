class Solution {
public:
    long long fastPow(long long base, long long pow) {
        long long ret = 1;
        while (pow) {
            if (pow & 1) ret = ret * base % mod;
            base = base * base % mod;
            pow >>= 1;
        }
        return ret;
    }
    
    const int mod = 1e9 + 7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);
        for (auto &edge : edges) {
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<int> q;
        vector<int> dist(n, -1);
        
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (auto &to : adjList[from]) {
                if (dist[to] == -1) {
                    dist[to] = dist[from] + 1;
                    q.push(to);
                }
            }
        }

        vector<long long> fact(n + 1, 1), rev(n + 1, 1);
        for (int i = 2; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        rev[n] = fastPow(fact[n], mod - 2);
        for (int i = n - 1; i >= 1; i--) rev[i] = rev[i + 1] * (i + 1) % mod;

        int depth = *max_element(dist.begin(), dist.end());
        long long ans = 0;
        for (int i = 0; i <= depth; i += 2) {
            long long comb = fact[depth] * rev[i] % mod * rev[depth - i] % mod;
            ans = (ans + comb) % mod;
        }
        
        return ans;
    }
};
