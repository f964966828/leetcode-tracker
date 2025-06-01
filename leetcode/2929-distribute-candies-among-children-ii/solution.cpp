class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            int remain = n - i;
            if (remain <= limit) {
                ans += (remain + 1);
            } else {
                ans += max(0, remain + 1 - 2 * (remain - limit));
            }
        }
        return ans;
    }
};
