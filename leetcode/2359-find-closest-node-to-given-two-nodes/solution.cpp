class Solution {
public:
    void dfs(int from, vector<int>& dist, vector<vector<int>>& adjList) {
        for (auto &to : adjList[from]) {
            if (dist[to] == -1) {
                dist[to] = dist[from] + 1;
                dfs(to, dist, adjList);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adjList[i].push_back(edges[i]);
            }
        }

        vector<int> dist1(n, -1), dist2(n, -1);
        dist1[node1] = dist2[node2] = 0;
        dfs(node1, dist1, adjList);
        dfs(node2, dist2, adjList);

        int mn = INT_MAX, ans = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int dist = max(dist1[i], dist2[i]);
                if (dist < mn) {
                    mn = dist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};
