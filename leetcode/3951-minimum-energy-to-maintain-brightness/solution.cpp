class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long count = 0;
        int s = intervals[0][0], e = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int ns = intervals[i][0], ne = intervals[i][1];
            if (ns <= e) {
                e = max(e, ne);
            } else {
                count += (e - s + 1);
                s = ns;
                e = ne;
            }
        }
        count += (e - s + 1);
        return count * ((brightness + 2) / 3);
    }
};
