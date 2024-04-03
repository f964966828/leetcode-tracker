class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m;
    string word;
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    
    bool dfs(int x, int y, int pos) {
        if (pos == word.size()) {
            return true;
        }

        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && board[nx][ny] == word[pos] && !visited[nx][ny]
                && dfs(nx, ny, pos + 1)
            ) {
                return true;
            }
        }
        visited[x][y] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        this->word = word;
        this->board = board;
        visited.resize(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
