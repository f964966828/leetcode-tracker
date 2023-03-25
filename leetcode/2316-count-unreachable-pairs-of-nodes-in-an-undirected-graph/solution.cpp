class Solution {
public:
    vector<vector<int>> adj_list;
    vector<int> visited;

    int dfs(int from){
        visited[from] = 1;
        
        int count = 1;
        for(auto to: adj_list[from]){
            if(!visited[to]){
                count += dfs(to);
            }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        adj_list.resize(n);
        for(auto e: edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        visited.resize(n);
        vector<int> groups;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                groups.push_back(dfs(i));
            }
        }

        long long ans = 0, sum = 0;
        for(int g: groups) sum += g;
        for(int g: groups) ans += g * (sum-g);

        return ans / 2;
    }
};
