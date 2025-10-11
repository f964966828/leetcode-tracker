class Solution {
public:
    vector<int> p;
    vector<int> rev;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        int gx = find(x);
        int gy = find(y);
        if (gx != gy) p[gy] = gx;
    }
    
    int maxPartitionFactor(vector<vector<int>>& points) {
        set<vector<int>> st; // (dist, i, j)
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                st.insert({dist, i, j});
            }
            p.push_back(i);
            rev.push_back(i);
        }

        for (auto & vec : st) {
            int i = vec[1], j = vec[2];
            if (rev[i] != i) merge(rev[i], j);
            if (rev[j] != j) merge(rev[j], i);
            if (find(i) == find(j)) return vec[0];
                                   
            rev[i] = j;
            rev[j] = i;
        }

        return 0;
    }
};
