class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        vector<vector<int>> points2(points);
        sort(points.begin(), points.end());
        sort(points2.begin(), points2.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] != b[1] ? a[1] > b[1] : a[0] < b[0]);
        });

        int ans = 0;
        for (auto &p1 : points) {
            int x1 = p1[0], y1 = p1[1], cur = INT_MAX;
            for (auto &p2 : points2) {
                int x2 = p2[0], y2 = p2[1];
                if (x1 == x2 && y1 == y2) continue;
                if (x2 < x1 || y2 > y1) continue;
                if (x2 < cur) {
                    cur = x2;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
