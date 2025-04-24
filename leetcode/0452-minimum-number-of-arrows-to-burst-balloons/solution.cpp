bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0, n = points.size(), i = 0;
        while (i < n) {
            int current = points[i][1];
            while (i < n && points[i][0] <= current) i++;
            ans++;
        }
        return ans;
    }
};
