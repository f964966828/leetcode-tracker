class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int start = toBeRemoved[0], end = toBeRemoved[1];
        for (auto &itv : intervals) {
            if (itv[1] <= start || itv[0] >= end) {
                ans.push_back(itv);
            } else if (itv[0] < start && itv[1] > end) {
                ans.push_back({itv[0], start});
                ans.push_back({end, itv[1]});
            } else if (itv[0] < start && itv[1] >= start) {
                ans.push_back({itv[0], start});
            } else if (itv[0] <= end && itv[1] > end) {
                ans.push_back({end, itv[1]});
            }
        }
        return ans;
    }
};
