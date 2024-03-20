bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto interval: intervals) {
            if (pq.size() != 0 && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }

        return pq.size();
    }
};
