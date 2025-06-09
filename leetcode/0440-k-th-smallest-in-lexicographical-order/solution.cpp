class Solution {
public:
    int getChildNumber(long long num, long long n) {
        if (num == 0) return n;

        int child = 0, factor = 0;
        while (num <= n) {
            child += min(n - num + 1, (long long) pow(10, factor));
            num *= 10;
            factor += 1;
        }
        return child;
    }

    int findKthNumber(int n, int k) {
        stack<long long> q;
        q.push(0);
        while (!q.empty()) {
            long long num = q.top();
            q.pop();

            if (k == 0) return num;

            int child = getChildNumber(num, n);
            if (child < k) {
                k -= child;
                continue;
            } else {
                k -= 1;
                for (int i = 9; i >= 0; i--) {
                    long long next = num * 10 + i;
                    if (next == 0 || next > n) continue;
                    q.push(next);
                }
            } 
        }

        return -1;
    }
};
