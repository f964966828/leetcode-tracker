class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> find(n), visited(n), bfs;
        for (auto &box : initialBoxes) {
            if (status[box]) {
                bfs.push_back(box);
            } else {
                find[box] = 1;
            }
        }

        int ans = 0;
        while (!bfs.empty()) {
            int idx = bfs.back();
            bfs.pop_back();
            ans += candies[idx];

            for (auto &key : keys[idx]) {
                if (find[key] && !visited[key]) {
                    bfs.push_back(key);
                    visited[key] = 1;
                }
                status[key] = 1;
            }

            for (auto &box : containedBoxes[idx]) {
                if (status[box] && !visited[box]) {
                    bfs.push_back(box);
                    visited[box] = 1;
                }
                find[box] = 1;
            }
        }

        return ans;
    }
};
