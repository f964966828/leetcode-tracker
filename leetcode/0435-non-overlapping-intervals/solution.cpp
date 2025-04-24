bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, current = INT_MIN, n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] < current) {
                ans++;
            } else {
                current = intervals[i][1];
            }
        }
        return ans;
    }
};
