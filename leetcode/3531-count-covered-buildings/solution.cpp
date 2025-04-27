class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> rowMap, colMap;
        for (auto &b : buildings) {
            rowMap[b[0]].insert(b[1]);
            colMap[b[1]].insert(b[0]);
        }

        int ans = 0;
        for (auto &b : buildings) {
            int r = b[0], c = b[1];
            set<int> &rowSet = rowMap[r], &colSet = colMap[c];
            auto rowIter = rowSet.lower_bound(c);
            auto colIter = colSet.lower_bound(r);
            if (
                rowIter != rowSet.begin() &&
                (rowIter != rowSet.end() && next(rowIter) != rowSet.end()) &&
                colIter != colSet.begin() &&
                (colIter != colSet.end() && next(colIter) != colSet.end())
            ) ans++;
        }

        return ans;
    }
};
