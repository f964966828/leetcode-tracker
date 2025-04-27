using LL = long long;

class Solution {
public:
    LL mod = 1e9 + 7;
    LL fast_pow(LL base, LL pow) {
        LL ret = 1;
        while (pow) {
            if (pow & 1) ret = (ret * base) % mod;
            base = (base * base) % mod;
            pow >>= 1;
        }
        return ret;
    }

    LL hash(string &str, int len) {
        LL ret = 0;
        for (int i = 0; i < len; i++) {
            ret = ((ret * 26) % mod + (str[i] - 'a')) % mod;
        }
        return ret;
    }

    vector<bool> solve(string &str, string &pattern) {
        vector<bool> flags(str.size(), false);
        int n = pattern.size(), pos = 0;
        LL str_hash = hash(str, n), pat_hash = hash(pattern, n);
        
        if (str_hash == pat_hash) {
            for (int i = 0; i < n; i++) flags[i] = true;
            pos = n;
        }
        
        for (int i = n; i < str.size(); i++) {
            str_hash = (str_hash - (str[i - n] - 'a') * fast_pow(26, n - 1) % mod + mod) % mod;
            str_hash = ((str_hash * 26) % mod + (str[i] - 'a')) % mod;
            if (str_hash == pat_hash) {
                for (int j = max(pos, i - n + 1); j <= i; j++) flags[j] = true;
                pos = i + 1;
            }
        }
        
        return flags;
    }
    
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = grid.size(), m = grid[0].size();
        string vertical = "", horizontal = "";
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) vertical += grid[j][i];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) horizontal += grid[i][j];

        vector<bool> ver_flag = solve(vertical, pattern);
        vector<bool> hor_flag = solve(horizontal, pattern);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ver_flag[i + j * n]) cout << "ver " << i << " " << j << endl;
                if (hor_flag[i * m + j]) cout << "hor " << i << " " << j << endl;
                ans += (ver_flag[i + j * n] && hor_flag[i * m + j]);
            }
        }
        
        return ans;
    }
};
