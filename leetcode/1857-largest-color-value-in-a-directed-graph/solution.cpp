class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        
        vector<int> in_nodes(n);
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            in_nodes[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        queue<int> bfs;
        for (int i=0; i<n; i++) {
            if (!in_nodes[i]) bfs.push(i);
        }

        int ans = -1, node_count = 0;
        vector<int> visited(n);
        vector<vector<int>> count(n, vector<int>(26));
        while (!bfs.empty()) {
            node_count++;

            int from = bfs.front(); bfs.pop();
            visited[from] = 1;
            ans = max(ans, ++count[from][colors[from] - 'a']);

            for (int to: adj[from]) {
                if (!visited[to]) {
                    for (int i=0; i<26; i++) {
                        count[to][i] = max(count[to][i], count[from][i]);
                    }
                    if (--in_nodes[to] == 0) {
                        bfs.push(to);
                    }
                }
            }
        }

        return (node_count < n ? -1 : ans);
    }
};
