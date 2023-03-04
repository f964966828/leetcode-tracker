class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 2*n-1;
        for(int i=1; i<n; i++) ans += 2*(2*i-1);
        return ans;
    }
};
