class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        bool change = true;
        while (change) {
            change = false;
            vector<vector<int>> newBoard(n, vector<int>(m, -1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + 2 < n && board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) {
                        newBoard[i][j] = newBoard[i + 1][j] = newBoard[i + 2][j] = 0;
                        change = true;
                    }
                    if (j + 2 < m && board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                        newBoard[i][j] = newBoard[i][j + 1] = newBoard[i][j + 2] = 0;
                        change = true;
                    }
                    if (newBoard[i][j] == -1) newBoard[i][j] = board[i][j];
                }
            }
            board = newBoard;

            for (int j = 0; j < m; j++) {
                int offset = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if (board[i][j] == 0) {
                        offset++;
                    } else if (offset != 0) {
                        swap(board[i + offset][j], board[i][j]);
                    }
                }
            }
        }

        return board;
    }
};
