class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, mx = 0, mn = 0;
        for (int num : differences) {
            sum += num;
            mx = max(mx, sum);
            mn = min(mn, sum);
        }

        return max((int)((upper - lower) - (mx - mn) + 1), 0);
    }
};
