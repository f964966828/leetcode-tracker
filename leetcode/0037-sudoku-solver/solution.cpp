class Solution {
public:

    int rflag[9][9] = {0}, cflag[9][9] = {0}, bflag[9][9] = {0};
    bool finish = false;
    
    void solve(int r, int c, vector<vector<char>>& board) {
        if (r == 9 && c == 0) {
            finish = true;
            return;
        }

        int nr = (c == 8 ? r + 1 : r);
        int nc = (c == 8 ? 0 : c + 1);
        int b = 3 * (r / 3) + c / 3;
        if (board[r][c] == '.') {
            for (int v = 0; v < 9; v++) {
                if (rflag[r][v] || cflag[c][v] || bflag[b][v]) continue;
                
                board[r][c] = '1' + v;
                rflag[r][v] = cflag[c][v] = bflag[b][v] = 1;
                solve(nr, nc, board);
        
                if (!finish) {
                    rflag[r][v] = cflag[c][v] = bflag[b][v] = 0;
                    board[r][c] = '.';
                }
            }
        } else {
            solve(nr, nc, board);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++){
                if (board[r][c] == '.') continue;
                int b = 3 * (r / 3) + c / 3;
                int v = board[r][c] - '1';
                rflag[r][v] = cflag[c][v] = bflag[b][v] = 1;
            }
        }
        solve(0, 0, board);
    }
};
