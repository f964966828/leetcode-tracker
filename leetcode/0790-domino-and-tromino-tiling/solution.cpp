class Solution {
public:
    int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int> full(n + 2), part(n + 2);
        part[1] = 0;
        part[2] = 1;
        full[1] = 1;
        full[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            part[i] = (full[i - 2] + part[i - 1]) % mod;
            full[i] = ((full[i - 2] + full[i - 1]) % mod + part[i - 1] * 2 % mod) % mod;
        }

        return full[n];
    }
};
