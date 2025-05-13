class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> counts(26);
        for (char &ch : s) counts[ch - 'a']++;

        int idx = 0;
        while (t--) {
            counts[idx] = (counts[idx] + counts[(idx + 25) % 26]) % mod;
            idx = (idx + 25) % 26;
        }
        
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans =  (ans + counts[i]) % mod;
        }

        return ans;
    }
};
