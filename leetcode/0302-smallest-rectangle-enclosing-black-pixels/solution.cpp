int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size(), m = image[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
        
        stack<pair<int, int>> stk;
        stk.push({x, y});
        while (!stk.empty()) {
            x = stk.top().first;
            y = stk.top().second;
            stk.pop();

            visited[x][y] = true;

            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == '1' && !visited[nx][ny]) {
                    stk.push({nx, ny});
                }
            }
        }

        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};
