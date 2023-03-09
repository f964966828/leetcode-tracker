class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0, mn = 1e9, mx = 0;
        for(int n: salary){
            sum += n;
            mn = min(mn, (double)n);
            mx = max(mx, (double)n);
        }
        return (sum-mn-mx) / (salary.size()-2);
    }
};
