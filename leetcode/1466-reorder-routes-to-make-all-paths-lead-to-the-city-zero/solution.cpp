class Solution {
public:
    int dfs(int i, vector<int>& visited, vector<vector<pair<int,int>>>& adj){
        visited[i] = 1;
        
        int ret = 0;
        for(auto c: adj[i]){
            int to = c.first;
            int rev = c.second;
            if(!visited[to]){
                ret += dfs(to, visited, adj);
                ret += rev;
            }
        }

        return ret;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto c: connections){
            int from = c[0];
            int to = c[1];
            adj[from].push_back({to, 1});
            adj[to].push_back({from, 0});
        }

        vector<int> visited(n);
        int ans = dfs(0, visited, adj);

        return ans;
    }
};
