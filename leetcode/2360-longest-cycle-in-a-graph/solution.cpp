class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size());

        int ans = -1, time = 1;
        for(int i=0; i<edges.size(); i++){
            if(visited[i])
                continue;

            int u = i, startTime = time;
            while(u != -1 && !visited[u]){
                visited[u] = time++;
                u = edges[u];
            }
            if(u != -1 && visited[u] >= startTime)
                ans = max(ans, time - visited[u]);
        }

        return ans;
    }
};
