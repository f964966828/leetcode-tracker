class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(1, vector<int>(1, 1));
        for(int i=1; i<numRows; i++){
            vector<int> row;

            row.push_back(1);
            for(int j=0; j<i-1; j++)
                row.push_back(ret[i-1][j] + ret[i-1][j+1]);
            row.push_back(1);

            ret.push_back(row);
        }
        return ret;
    }
};
