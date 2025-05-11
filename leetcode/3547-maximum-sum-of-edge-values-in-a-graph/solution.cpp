class Solution {
public:
    int dfs(int from, vector<vector<int>> &adj_list, vector<bool> &visited) {
        visited[from] = true;
        for (auto &to : adj_list[from]) {
            if (!visited[to]) return dfs(to, adj_list, visited) + 1;       
        }
        return 1;
    }
    
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<int> in_nodes(n);
        for (auto &edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
            in_nodes[edge[0]]++;
            in_nodes[edge[1]]++;
        }

        vector<bool> visited(n, false);
        vector<int> line, cycle;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && in_nodes[i] == 1) line.push_back(dfs(i, adj_list, visited));
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) cycle.push_back(dfs(i, adj_list, visited));
        }

        sort(line.rbegin(), line.rend());
        sort(cycle.rbegin(), cycle.rend());

        long long ans = 0;
        for (int &c : cycle) {
            if (c == 1) continue;
            vector<long long> vec(c);
            for (int i = 0; i < (c + 1) / 2; i++) vec[i] = n - 2 * i;
            for (int i = 0; i < c / 2; i++) vec[c - 1 - i] = n - 1 - 2 * i;
            for (int i = 0; i < c - 1; i++) ans += vec[i] * vec[i + 1];
            ans += vec[0] * vec[c - 1];
            n -= c;
        }

        for (int &l : line) {
            vector<long long> vec(l);
            n -= l;
            for (int i = 0; i < (l + 1) / 2; i++) vec[i] = n + 2 * i + 1;
            for (int i = 0; i < l / 2; i++) vec[l - 1 - i] = n + 2 * i + 2;
            for (int i = 0; i < l - 1; i++) ans += vec[i] * vec[i + 1];
        }

        return ans;
    }
};
