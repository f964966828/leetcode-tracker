class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = n - 1, pos = 0;
        while (x) {
            if (x & 1) {
                long long r = ans & ((1 << pos) - 1), l = ans - r;
                ans = (l << 1) + (1 << pos) + r; 
            }
            x >>= 1;
            pos++;
        }
        return ans;
    }
};
