class Solution {
public:
    int minOperations(int k) {
        int n = 1;
        while (n * n < k) n++;
        
        return n - 1 + (k / n) - (k % n == 0);
    }
};
