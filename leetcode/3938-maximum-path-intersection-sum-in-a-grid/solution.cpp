class Solution {
public:
    int lineMaxScore(vector<int>& line) {
        int sum = 0, mx = INT_MIN, mn = 0, n = line.size();
        for (int i = 0; i < n; i++) {
            sum += line[i];
            if (i != 0) mx = max(mx, sum - mn);
            if (i != n - 2) mn = min(mn, sum);
        }
        return mx;
    }

    int borderLineMaxScore(vector<int>& line) {
        int sum = 0, mx = INT_MIN, n = line.size();
        vector<int> mn(n + 1);
        for (int i = 0; i < n; i++) {
            sum += line[i];
            if (i != 0) mx = max(mx, sum - mn[i - 1]);
            mn[i + 1] = min(mn[i], sum);
        }
        return mx;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            int score = 0;
            if (i == 0 || i == n - 1) score = borderLineMaxScore(grid[i]);
            else score = lineMaxScore(grid[i]);
            ans = max(ans, score);
        }
        for (int i = 0; i < m; i++) {
            vector<int> line;
            for (int j = 0; j < n; j++) line.push_back(grid[j][i]);
            
            int score = 0;
            if (i == 0 || i == m - 1) score = borderLineMaxScore(line);
            else score = lineMaxScore(line);
            ans = max(ans, score);
        }
        return ans;
    }
};
