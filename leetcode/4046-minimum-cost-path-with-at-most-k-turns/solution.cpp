int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

typedef tuple<int, int, int, int, int> step; // (-cost, row, col, dist, dir)

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        priority_queue<step> pq;
        for (int d = 0; d < 4; d++) {
            pq.push({-grid[0][0], 0, 0, 0, d});
        }

        int n = grid.size(), m = grid[0].size();
        int visited[75][75][75][4] = {0}; // (row, col, dist, dir)
        while (!pq.empty()) {
            auto [cost, row, col, dist, dir] = pq.top();
            pq.pop();

            if (row == n - 1 && col == m - 1) return -cost;
            if (visited[row][col][dist][dir]) continue;
            visited[row][col][dist][dir] = true;

            for (int d = 0; d < 4; d++) {
                if ((d + 2) % 4 == dir) continue;

                int nrow = row + dr[d];
                int ncol = col + dc[d]; 

                if (!(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)) continue;
                int ncost = cost - grid[nrow][ncol];
                int ndist = dist + (d != dir);
                
                if (!visited[nrow][ncol][ndist][d] && ndist <= k) {
                    pq.push({ncost, nrow, ncol, ndist, d});
                }
            }
        }

        return -1;
    }
};
