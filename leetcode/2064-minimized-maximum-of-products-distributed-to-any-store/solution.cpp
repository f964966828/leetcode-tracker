class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5, ans = 1e5;
        while (l <= r) {
            int mid = (l + r) / 2, count = 0;
            for (int q : quantities) count += (q / mid + (q % mid != 0));
            if (count <= n) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
