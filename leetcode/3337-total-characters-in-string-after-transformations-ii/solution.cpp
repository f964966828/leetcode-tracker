using ll = long long;

class Solution {
public:
    int mod = 1e9 + 7;

    vector<vector<ll>> fastPow(vector<vector<ll>> &base, int pow) {
        vector<vector<ll>> ret(26, vector<ll>(26));
        for (int i = 0; i < 26; i++) ret[i][i] = 1; // identity matrix;
        while (pow) {
            if (pow & 1) ret = matMul(ret, base);
            base = matMul(base, base);
            pow >>= 1;
        }
        return ret;
    }

    vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        vector<vector<ll>> ret(26, vector<ll>(26));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    ret[i][k] = (ret[i][k] + (a[i][j] * b[j][k]) % mod) % mod;
                }
            }
        }
        return ret;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> trans(26, vector<ll>(26));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < nums[i]; j++) {
                trans[i][(i + j + 1) % 26] = 1;
            }
        }
        trans = fastPow(trans, t);

        vector<int> counts(26);
        for (char &ch : s) counts[ch - 'a']++;
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = (ans + (counts[i] * trans[i][j]) % mod) % mod;
            }
        }

        return ans;
    }
};
