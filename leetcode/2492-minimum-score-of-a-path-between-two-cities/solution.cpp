class Solution {
public:
    void dfs(int i, vector<int> &visited, vector<vector<int>> &adj){
        visited[i] = 1;
        for(int to: adj[i]){
            if(!visited[to]){
                dfs(to, visited, adj);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<int>> adj(n+1);
        for(auto road: roads){
            int from = road[0];
            int to = road[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<int> visited(n+1);
        dfs(1, visited, adj);

        int ans = INT_MAX;
        for(auto road: roads){
            int from = road[0];
            int to = road[1];
            int dis = road[2];
            if(visited[from])
                ans = min(ans, dis);
        }  

        return ans;
    }
};
