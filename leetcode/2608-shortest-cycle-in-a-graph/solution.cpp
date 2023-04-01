class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = n + 1; // initialize answer to a value larger than any possible cycle length
        
        // iterate over all nodes and start BFS from each one
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, -1); // initialize all distances to -1 (i.e., unreachable)
            queue<int> q;
            dist[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } else if(dist[v] != dist[u] - 1) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans; // return -1 if no cycle was found
    }
};
