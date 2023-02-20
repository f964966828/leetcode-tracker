class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rflag[9][9] = {0}, cflag[9][9] = {0}, bflag[9][9] = {0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int b = 3*(i/3) + j/3, v = board[i][j]-'1';
                if(rflag[i][v] || cflag[j][v] || bflag[b][v])
                    return false;
                else
                    rflag[i][v] = cflag[j][v] = bflag[b][v] = 1;
            }
        }
        return true;
    }
};
