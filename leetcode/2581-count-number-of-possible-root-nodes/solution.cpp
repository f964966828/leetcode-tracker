class Solution {
public:
    
    vector<vector<int>> adj_list;
    vector<set<int>> guess;
    
    int traverse1(vector<int>& visited, int from){
        int cnt = 0;
        visited[from] = 1;
        for(int to: adj_list[from]){
            if(visited[to]) continue;
            cnt += traverse1(visited, to);
            if(guess[from].find(to) != guess[from].end()) cnt++;
        }
        
        return cnt;
    }
    
    int traverse2(vector<int>& visited, int from, int cnt, int k){
        int ans = 0;
        if(cnt >= k) ans++;
        visited[from] = 1;
        for(int to: adj_list[from]){
            if(visited[to]) continue;
            int sub = (guess[from].find(to) != guess[from].end());
            int add = (guess[to].find(from) != guess[to].end());
            ans += traverse2(visited, to, cnt-sub+add, k);
        }
        
        return ans;
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        
        adj_list.resize(n);
        for(auto e: edges){;
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        guess.resize(n);
        for(auto g: guesses){
            guess[g[0]].insert(g[1]);  
        }
        
        vector<int> visited(n);
        int cnt = traverse1(visited, 0);
        
        for(int i=0; i<n; i++) visited[i] = 0;
        int ans = traverse2(visited, 0, cnt, k);
        
        return ans;
    }
};
