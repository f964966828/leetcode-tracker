class Solution {
public:
    const int mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> counts(forget);
        counts[0] = 1;
        while (--n) {
            int total = 0;
            for (int i = forget - 2; i >= 0; i--) {
                counts[i + 1] = counts[i];
                if (i + 1 >= delay) total = (total + counts[i]) % mod;
            }
            counts[0] = total;
        }

        int ans = 0;
        for (auto &c : counts) ans = (ans + c) % mod;
        return ans;
    }
};
