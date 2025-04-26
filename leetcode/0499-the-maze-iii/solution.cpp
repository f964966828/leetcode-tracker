int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dire[] = {'r', 'd', 'l', 'u'};

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> distance(n, vector<int>(m));
        vector<vector<string>> path(n, vector<string>(m));

        priority_queue<tuple<int, int, int>> pq; // (dist, x, y)
        pq.push({1, ball[0], ball[1]});
        distance[ball[0]][ball[1]] = 1;
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x, ny = y, nd = distance[x][y];
                while (
                    nx + dx[i] >= 0 && nx + dx[i] < n 
                    && ny + dy[i] >= 0 && ny + dy[i] < m
                    && !maze[nx + dx[i]][ny + dy[i]]
                    && !(nx == hole[0] && ny == hole[1])
                ) {
                    nx += dx[i];
                    ny += dy[i];
                    nd += 1;
                }
                if (!distance[nx][ny] || distance[nx][ny] > nd || (distance[nx][ny] == nd && path[nx][ny] > path[x][y] + dire[i])) {
                    distance[nx][ny] = nd;
                    path[nx][ny] = path[x][y] + dire[i];
                    pq.push({nd, nx, ny});
                }
            }
        }

        if (distance[hole[0]][hole[1]]) {
            return path[hole[0]][hole[1]];
        } else {
            return "impossible";
        }
    }
};
