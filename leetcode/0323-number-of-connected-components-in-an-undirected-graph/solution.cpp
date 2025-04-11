class Solution {
public:
    void dfs(int from, vector<bool>& visited, vector<vector<int>>& adj_list) {
        visited[from] = true;
        for (int to : adj_list[from]) {
            if (!visited[to]) dfs(to, visited, adj_list);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for (auto edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj_list);
                ans++;
            }
        }

        return ans;
    }
};
