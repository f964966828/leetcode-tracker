class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) ans++;
        }

        return ans;
    }
};
