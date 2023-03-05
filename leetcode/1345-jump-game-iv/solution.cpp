class Solution {
public:

    int minJumps(vector<int>& arr) {

        if(arr.size() == 1)
            return 0;

        int n = arr.size();
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]].push_back(i);

        vector<int> bfs(1), visited(n);
        int ans = 1;
        visited[0] = 1;
        while(!bfs.empty()){
            vector<int> bfs2;
            for(int from: bfs){
                vector<int> des;
                des.push_back(from+1);
                des.push_back(from-1);
                for(int to: mp[arr[from]]) des.push_back(to);
                mp.erase(arr[from]);
                for(int to: des){
                    if(to<0 || to>=n || visited[to]) continue;
                    visited[to] = 1;
                    bfs2.push_back(to);
                    if(to == n-1) return ans;  
                }
            }
            bfs = bfs2;
            ans++;
        }

        return -1;
    }
};
