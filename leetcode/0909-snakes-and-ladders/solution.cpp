int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        vector<int> dist(n * m + 1, -1);
        queue<int> q;
        
        q.push(1);
        dist[1] = 0;
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (int d = 1; d <= 6; d++) {
                int to = from + d;
                if (to <= n * m) {
                    int x = n - (to / m + (to % m != 0));
                    int y = ((n - x) % 2 == 0 ? (n - x) * m - to : to - (n - x - 1) * m - 1 );
                    if (board[x][y] != -1) to = board[x][y];
                    if (dist[to] == -1) {
                        q.push(to);
                        dist[to] = dist[from] + 1;
                    }
                }
            }
        }

        return dist[n * m];
    }
};
