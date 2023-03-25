class Solution {
public:
    void dfs(int from, vector<int>& visited, vector<vector<int>>& isConnected){
        visited[from] = 1;
        
        int n = isConnected.size();
        for(int i=0; i<n; i++){
            if(isConnected[from][i] && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);

        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited, isConnected);
            }
        }

        return ans;
    }
};
