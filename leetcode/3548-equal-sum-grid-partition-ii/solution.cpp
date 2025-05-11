class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rowSum(n + 1), colSum(m + 1);
        unordered_map<long long, int> leftMap, rightMap, upMap, downMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i + 1] += grid[i][j];
                colSum[j + 1] += grid[i][j];
                rightMap[grid[i][j]]++;
                downMap[grid[i][j]]++;
            }
        }
        for (int i = 0; i < n; i++) rowSum[i + 1] += rowSum[i];
        for (int j = 0; j < m; j++) colSum[j + 1] += colSum[j];

        for (int i = 1; i < n; i++) {
            long long left = rowSum[i], right = rowSum[n] - left;
            for (int j = 0; j < m; j++) {
                long long val = grid[i - 1][j];
                rightMap[val]--;
                leftMap[val]++;
                if (rightMap[val] == 0) rightMap.erase(val);
            }
            if (left > right) {
                long long target = left - right;
                if (i == 1) {
                    if (grid[0][0] == target || grid[0][m - 1] == target) return true;
                } else if (m == 1) {
                    if (grid[0][0] == target || grid[i - 1][0] == target) return true;
                } else {
                    if (leftMap.find(target) != leftMap.end()) return true;
                }
            } else if (left < right) {
                long long target = right - left;
                if (i == n - 1) {
                    if (grid[n - 1][0] == target || grid[n - 1][m - 1] == target) return true;
                } else if (m == 1) {
                    if (grid[n - 1][0] == target || grid[i][0] == target) return true;
                } else {
                    if (rightMap.find(target) != rightMap.end()) return true;
                }
            } else {
                return true;
            }
        }

        for (int j = 1; j < m; j++) {
            long long up = colSum[j], down = colSum[m] - up;
            for (int i = 0; i < n; i++) {
                long long val = grid[i][j - 1];
                downMap[val]--;
                upMap[val]++;
                if (downMap[val] == 0) downMap.erase(val);
            }
            if (up > down) {
                long long target = up - down;
                if (j == 1) {
                    if (grid[0][0] == target || grid[n - 1][0] == target) return true;   
                } else if (n == 1) {
                    if (grid[0][0] == target || grid[0][j - 1] == target) return true;
                } else {
                    if (upMap.find(target) != upMap.end()) return true;
                }
            } else if (up < down) {
                long long target = down - up;
                if (j == m - 1) {
                    if (grid[0][m - 1] == target || grid[n - 1][m - 1] == target) return true;
                } else if (n == 1) {
                    if (grid[0][m - 1] == target || grid[0][j] == target) return true;
                } else {
                    if (downMap.find(target) != downMap.end()) return true;
                }
            } else {
                return true;
            }
        }

        return false;
    }
};
