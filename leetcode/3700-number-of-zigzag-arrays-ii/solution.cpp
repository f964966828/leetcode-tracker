class Solution {
public:
    const int mod = 1e9 + 7;

    vector<vector<int>> mat_mul(vector<vector<int>>& a, vector<vector<int>>& b) {
        int d = a.size();
        vector<vector<int>> ret(d, vector<int>(d));
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                for (int k = 0; k < d; k++) {
                    ret[i][j] = (ret[i][j] + (long long) a[i][k] * b[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> fast_pow(vector<vector<int>> base, int power) {
        int d = base.size();
        vector<vector<int>> ret(d, vector<int>(d));
        for (int i = 0; i < d; i++) ret[i][i] = 1; // identity matrix
        while (power) {
            if (power & 1) ret = mat_mul(ret, base);
            base = mat_mul(base, base);
            power >>= 1;
        }
        return ret;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int d = r - l + 1;
        vector<vector<int>> up_mat(d, vector<int>(d));
        vector<vector<int>> down_mat(d, vector<int>(d));
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                if (i < j) up_mat[i][j] = 1;
                if (i > j) down_mat[i][j] = 1;
            }
        }
        
        vector<vector<int>> base = mat_mul(up_mat, down_mat);
        vector<vector<int>> ret = fast_pow(base, (n - 1) / 2);
        if (n % 2 == 0) ret = mat_mul(ret, up_mat);

        int ans = 0;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                ans = (ans + ret[i][j]) % mod;
            }
        }
        
        return (ans * 2) % mod;
    }
};
