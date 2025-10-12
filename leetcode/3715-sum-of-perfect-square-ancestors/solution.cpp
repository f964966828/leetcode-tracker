class Solution {
public:
    int process(int num) {
        vector<pair<int, int>> factor;
        for (int i = 2; i * i <= num; i++) {
            int count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            if (count) factor.push_back({i, count});
        }

        for (auto & [first, second] : factor) {
            if (second % 2) num *= first;
        }

        return num;
    }

    long long dfs(int from, vector<vector<int>>& adj_list, vector<int>& nums, vector<bool>& visited, map<int, int>& mp) {
        visited[from] = true;
        
        int val = process(nums[from]);
        long long ans = mp[val]++;
        for (int & to : adj_list[from]) {
            if (!visited[to]) ans += dfs(to, adj_list, nums, visited, mp);
        }
        mp[val]--;
        return ans;
    }
    
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> adj_list(n);
        for (auto & edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        stack<int> stk;
        map<int, int> mp;
        return dfs(0, adj_list, nums, visited, mp);
    }
};
