class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rflag[9][9] = {0}, cflag[9][9] = {0}, bflag[9][9] = {0};
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++){
                if (board[r][c] == '.') continue;
                int b = 3 * (r / 3) + c / 3;
                int v = board[r][c] - '1';
                if (rflag[r][v] || cflag[c][v] || bflag[b][v]) return false;
                else rflag[r][v] = cflag[c][v] = bflag[b][v] = 1;
            }
        }
        return true;
    }
};
