class Solution {
public:
    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    void solve(int r, int c, int idx, vector<vector<int>>& board, vector<vector<int>>& visited, bool& find) {
        visited[r][c] = 1;
        board[r][c] = idx;

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                solve(nr, nc, idx + 1, board, visited, find);
            }
        }

        if (idx == m * n - 1) find = true;
        if (!find) visited[r][c] = 0;
    }

    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> board(m, vector<int>(n)), visited(m, vector<int>(n));

        bool find = false;
        solve(r, c, 0, board, visited, find);

        return board;
    }
};
