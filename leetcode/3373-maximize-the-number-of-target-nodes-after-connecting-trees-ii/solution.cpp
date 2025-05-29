class Solution {
public:
    void dfs(int from, vector<vector<int>>& adjList, vector<vector<int>>& targets) {
        targets[from][1] = 1;
        for (auto &to : adjList[from]) {
            if (targets[to][1] == 0) {
                targets[to][2] = targets[from][2] + 1;
                dfs(to, adjList, targets);
                targets[from][0] += targets[to][1];
                targets[from][1] += targets[to][0];
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adjList1(n), adjList2(m);
        for (auto &edge : edges1) {
            adjList1[edge[0]].push_back(edge[1]);
            adjList1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2) {
            adjList2[edge[0]].push_back(edge[1]);
            adjList2[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> targets1(n, vector<int>(3)), targets2(m, vector<int>(3)); // (odd, even, depth)
        dfs(0, adjList1, targets1);
        dfs(0, adjList2, targets2);
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (targets1[i][2] % 2) {
                ans.push_back(targets1[0][0] + max(targets2[0][0], targets2[0][1]));
            } else {
                ans.push_back(targets1[0][1] + max(targets2[0][0], targets2[0][1]));
            }
        }

        return ans;
    }
};
