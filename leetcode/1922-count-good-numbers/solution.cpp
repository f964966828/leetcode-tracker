int mod = 1e9 + 7;

class Solution {
public:
    long long fast_pow(long long base, long long power) {        
        int result = 1;
        while (power) {
            if (power & 1) result = (result * base) % mod;
            power >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_power = n / 2 + (n % 2), odd_power = n / 2;
        return (fast_pow(5, even_power) * fast_pow(4, odd_power)) % mod;
    }
};
