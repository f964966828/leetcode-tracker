class Solution {
public:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& adj){
        visited[i] = 1;
        for(auto to: adj[i]){
            if(!visited[to]){
                dfs(to, visited, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n > connections.size() + 1)
            return -1;

        vector<vector<int>> adj(n);
        for(auto c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        int ans = 0;
        vector<int> visited(n);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                ans++;
            }
        }

        return ans-1;
    }
};
