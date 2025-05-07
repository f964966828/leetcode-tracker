int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        priority_queue<vector<int>> pq; // {-time, row, col}
        pq.push({0, 0, 0});
        visited[0][0] = true;

        int ans = 0;
        while (!pq.empty()) {
            int t = -pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();
            if (r == n - 1 && c == m - 1) ans = t;

            visited[r][c] = true;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    pq.push({-(max(t, moveTime[nr][nc]) + 1), nr, nc});
                    visited[nr][nc] = true;
                } 
            }
        }
        return ans;
    }
};
