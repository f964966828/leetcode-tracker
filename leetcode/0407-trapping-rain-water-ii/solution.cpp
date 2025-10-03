int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int n;
    int m;

    vector<int> p;
    vector<int> gsize;
    vector<bool> valid;
    priority_queue<pair<int, int>> pq; // (-height, x * n + y)

    int find(int a) {
        return p[a] == a ? a : p[a] = find(p[a]);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size();
        m = heightMap[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p.push_back(i * m + j);
                gsize.push_back(0);
                valid.push_back(i != 0 && i != n - 1 && j != 0 && j != m - 1);
                pq.push({-heightMap[i][j], i * m + j});
            }
        }

        int ans = 0, count = 0, prev_count = 0, prev_height = 0;
        while (!pq.empty()) {
            int height = -pq.top().first;
            while (!pq.empty() && -pq.top().first == height) {
                int idx = pq.top().second;
                pq.pop();

                int g = find(idx);
                if (valid[g]) {
                    gsize[g]++;
                    count++;
                }

                int x = idx / m;
                int y = idx % m;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if (heightMap[nx][ny] <= height) { // union
                        int ng = find(nx * m + ny);
                        if (g == ng) continue;

                        if (!valid[g] || !valid[ng]) {
                            if (valid[g]) count -= gsize[g];
                            if (valid[ng]) count -= gsize[ng];
                        }

                        p[ng] = g;
                        gsize[g] += gsize[ng];
                        valid[g] = valid[g] && valid[ng];
                    }
                }
            }
            ans += prev_count * (height - prev_height);
            prev_count = count;
            prev_height = height;
        }

        return ans;
    }
};
