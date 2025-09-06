class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1], op = 1;
            long long prev = 1, cur = 4, cnt = 0;
            while (prev <= r) {
                if (cur > l) cnt += op * (min(cur - 1, r) - max(prev, l) + 1);
                op += 1;
                prev = cur;
                cur <<= 2;
            }
            ans += cnt / 2 + cnt % 2;
        }
        return ans;
    }
};
