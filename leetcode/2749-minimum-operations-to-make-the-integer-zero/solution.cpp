class Solution {
public:
    int count_bit(long long num) {
        int cnt = 0;
        while (num) {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }

    int makeTheIntegerZero(long long num1, long long num2) {
        int ans = 0;
        while (count_bit(num1) > ans) {
            num1 -= num2;
            ans++;
            if (num1 < ans) return -1;
        }
        return ans; 
    }
};
