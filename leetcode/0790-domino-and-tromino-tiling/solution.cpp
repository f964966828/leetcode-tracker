class Solution {
public:
    int mod = 1e9 + 7;
    int numTilings(int n) {
        int full = 1, prevFull = 1, part = 0, prevPart = 0;
        for (int i = 2; i <= n; i++) {
            int newPart = ((prevFull * 2) % mod + part) % mod;
            int newFull = ((prevFull + full) % mod + part) % mod;
            prevFull = full;
            prevPart = part;
            full = newFull;
            part = newPart;
        }

        return full;
    }
};
