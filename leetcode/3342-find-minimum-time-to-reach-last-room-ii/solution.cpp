int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        priority_queue<tuple<int, int, int, int>> pq; // {-time, step, row, col}
        pq.push({0, 0, 0, 0});

        int ans = 0;
        while (!pq.empty()) {
            auto [time, step, r, c] = pq.top();
            time = -time;
            pq.pop();

            if (visited[r][c]) {
                continue;
            } else if (r == n - 1 && c == m - 1) {
                ans = time;
            }
            visited[r][c] = true;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    int newTime = max(time, moveTime[nr][nc]) + step % 2 + 1;
                    pq.push({-newTime, step + 1, nr, nc});
                } 
            }
        }
        return ans;
    }
};
