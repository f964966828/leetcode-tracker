class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 1 - n; i <= n - 1; i++) {
            vector<int> vec;
            for (int y = 0; y < n; y++) {
                int x = i + y; // x - y = i;
                if (x >= 0 && x < n) vec.push_back(grid[x][y]);
            }

            sort(vec.begin(), vec.end());
            if (i < 0) reverse(vec.begin(), vec.end());

            for (int y = 0; y < n; y++) {
                int x = i + y; // x - y = i;
                if (x >= 0 && x < n) grid[x][y] = vec.back(), vec.pop_back();
            }
        }
        return grid;
    }
};
