int dy[] = {1, -1};

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> zigzag(numRows);
        int y = 0, dir = 0;
        for(char ch: s){
            zigzag[y].push_back(ch);

            if(y == 0) dir = 0;
            if(y == numRows-1) dir = 1;

            if(numRows != 1) y = y + dy[dir];
        }

        string ans;
        for(auto vec: zigzag){
            for(auto ch: vec) ans.push_back(ch);
        }

        return ans;
    }
};
