class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_nodes(numCourses);
        vector<vector<int>> adj_list(numCourses);
        for (auto pre: prerequisites) {
            in_nodes[pre[0]]++;
            adj_list[pre[1]].push_back(pre[0]);
        }

        queue<int> bfs;
        for (int i = 0; i < numCourses; i++) {
            if (in_nodes[i] == 0) {
                bfs.push(i);
            }
        }

        while (!bfs.empty()) {
            int from = bfs.front();
            bfs.pop();
            for (int to: adj_list[from]) {
                in_nodes[to]--;
                if (in_nodes[to] == 0) {
                    bfs.push(to);
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (in_nodes[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
