class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for (auto &edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        int counter = 0;
        vector<int> check(n, 1);
        while (n - counter > 2) {
            vector<int> in_nodes(n);
            for (auto &edge : edges) {
                int a = edge[0], b = edge[1];
                if (check[a] && check[b]) {
                    in_nodes[a]++;
                    in_nodes[b]++;
                }
            }
            for (int i = 0; i < n; i++) {
                if (in_nodes[i] == 1) {
                    check[i] = 0;
                    counter++;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (check[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
