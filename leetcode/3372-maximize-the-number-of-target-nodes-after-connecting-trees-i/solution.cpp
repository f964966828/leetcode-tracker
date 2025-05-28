class Solution {
public:
    int dfs(int from, int depth, int maxDepth, vector<bool>& visited, vector<vector<int>>& adjList) {
        visited[from] = true;
        if (depth > maxDepth) {
            return 0;
        }

        int target = 1;
        for (int &to : adjList[from]) {
            if (!visited[to]) {
                target += dfs(to, depth + 1, maxDepth, visited, adjList);
            }
        }
        return target;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adjList1(n), adjList2(m);
        for (auto &edge : edges1) {
            adjList1[edge[0]].push_back(edge[1]);
            adjList1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2) {
            adjList2[edge[0]].push_back(edge[1]);
            adjList2[edge[1]].push_back(edge[0]);
        }
        
        int maxTarget = -1;
        for (int i = 0; i < m; i++) {
            vector<bool> visited(m, false);
            int target = dfs(i, 0, k - 1, visited, adjList2);
            maxTarget = max(target, maxTarget);
        }

        vector<int> targets;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int target = dfs(i, 0, k, visited, adjList1);
            targets.push_back(target + maxTarget);
        }

        return targets;
    }
};
