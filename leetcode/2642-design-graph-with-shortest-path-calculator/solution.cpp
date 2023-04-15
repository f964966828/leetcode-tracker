class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[2], edge[1]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = adj.size();
        vector<int> dist(n, 1e9);
        dist[node1] = 0;
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, node1});
        
        while (!pq.empty()) {
            int u = pq.top().second, d = -pq.top().first; pq.pop();
            if (u == node2) return dist[u];
            if (d > dist[u]) continue;
            for (auto& [w, v] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        return -1; // node2 is not reachable from node1
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
