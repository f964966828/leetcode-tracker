class Solution {
public:
    void dfs(int from, int k, vector<int>& nums, vector<bool>& visited, vector<vector<int>>& adjList, vector<pair<long long, long long>>& dp) {
        visited[from] = true;
        long long selectedMax = INT_MIN, noneMax = 0;
        for (auto &to : adjList[from]) {
            if (!visited[to]) {
                dfs(to, k, nums, visited, adjList, dp);
                long long newSelectedMax = max(selectedMax + dp[to].second, noneMax + dp[to].first);
                long long newNoneMax = max(selectedMax + dp[to].first, noneMax + dp[to].second);
                selectedMax = newSelectedMax;
                noneMax = newNoneMax;
            }
        }
        dp[from].first = max(selectedMax + nums[from], noneMax + (nums[from] ^ k));
        dp[from].second = max(selectedMax + (nums[from] ^ k), noneMax + nums[from]);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adjList(n);
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<pair<long long, long long>> dp(n); // selected or not
        vector<bool> visited(n, false);
        dfs(0, k, nums, visited, adjList, dp);

        return dp[0].second;
    }
};
