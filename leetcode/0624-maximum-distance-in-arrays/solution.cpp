class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = 1e4, globalMax = -1e4, ans = 0;
        for (vector<int> &array : arrays) {
            int localMin = *array.begin(), localMax = array.back();
            ans = max(ans, max(localMax - globalMin, globalMax - localMin));
            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
        }
        return ans;
    }
};
