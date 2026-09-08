typedef long long ll;

class Solution {
public:
    const int mod = 1e9 + 7;

    ll fast_pow(ll x, ll y) {
        ll ret = 1;
        while (y) {
            if (y & 1) ret = (ret * x) % mod;
            x = (x * x) % mod;
            y >>= 1;
        }
        return ret;
    }
    
    int sumDecoded(vector<long long>& nums) {
        ll sum = 0;
        for (ll num : nums) {
            ll w = num % 10, d = num / 10;
            ll pw = pow(10, to_string(num).size() - 1 - w);
            ll x = d / pw, y = d % pw;
            sum = (sum + fast_pow(x, y)) % mod;
        }
        return sum;
    }
};
