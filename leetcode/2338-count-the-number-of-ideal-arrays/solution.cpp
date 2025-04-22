class Solution {
public:
    int mod = 1e9 + 7;

    long long quick_pow(long long base, long long pow) {
        int ret = 1;
        while (pow) {
            if (pow & 1) ret = (ret * base) % mod;
            base = (base * base) % mod;
            pow >>= 1;
        }
        return ret;
    }

    int idealArrays(int n, int maxValue) {
        vector<long long> fac(n + 101, 1), rev(n + 101, 1);
        for (int i = 1; i <= n + 100; i++) fac[i] = (fac[i - 1] * i) % mod;
        rev[n + 100] = quick_pow(fac[n + 100], mod - 2); // Fermat's little theorem
        for (int i = n + 99; i >= 0; i--) rev[i] = (rev[i + 1] * (i + 1)) % mod;

        long long ans = 1;
        for (int i = 2; i <= maxValue; i++) {
            long long temp = i, ret = 1;
            for (int j = 2; j * j <= temp; j++) {
                int k = 0;
                while (temp % j == 0) {
                    temp /= j;
                    k++;
                }
                if (k) {
                    // H(n, k) = C(n + k - 1, k) = (n + k - 1)! / (n - 1)! k! 
                    long long comb = (((fac[n + k - 1] * rev[n - 1]) % mod) * rev[k]) % mod;
                    ret = (ret * comb) % mod;
                }
            }
            if (temp != 1) ret = (ret * n) % mod;
            ans = (ans + ret) % mod;
        }
        return ans;
    }
};
