class Solution {
public:
    long long flowerGame(long long n, long long m) {
        return ((n + 1) / 2) * (m / 2) + (n / 2) * ((m + 1) / 2); 
    }
};
