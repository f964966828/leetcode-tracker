class Solution {
public:

    bool dfs(vector<vector<int>>& adj_list, vector<int>& visited, int from, int target) {
        if (from == target) {
            return true;
        }

        visited[from] = 1;
        for (int to: adj_list[from]) {
            if (!visited[to] && dfs(adj_list, visited, to, target)) {
                return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n);
        for (auto edge: edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n);
        return dfs(adj_list, visited, source, destination);
    }
};
