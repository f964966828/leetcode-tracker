class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        } else if (n > k) {
            return (long long) (n - k) * k;
        } else {
            return (long long) (m - k) * k;
        }
    }
};
